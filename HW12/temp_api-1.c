#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 30

#include "temp_api.h"
/*
struct sensor
{
    uint16_t year;  //год
    uint8_t month;  //месяц
    uint8_t day;    //день
    uint8_t hour;   //час
    uint8_t minute; //минуты
    int8_t t;       //температура
};
*/

// записать данные 1 раз
void AddRecord(struct sensor info[], int number, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t)
{
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].hour = hour;
    info[number].minute = minute;
    info[number].t = t;
}

// записать данные 1 раз d 1 структуру
void AddRecord_1str(struct sensor *info, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t)
{
    info->year = year;
    info->month = month;
    info->day = day;
    info->hour = hour;
    info->minute = minute;
    info->t = t;
}

// инициализация
void InitInfo(struct sensor info[], int n)
{
    for (int i = 0; i < n; i++)
    {
        AddRecord(info, i, 0, 0, 0, 0, 0, 0);
    }
}

// записать данные из простого файла
int AddInfoFromFileSimple(struct sensor info[], int start)
{
    struct sensor *ptr = info;

    FILE *file = fopen("SimpleData.txt", "r");
    if (file == NULL)
    {
        printf("Error open file\n");
        return -1;
    }
    int i = start;
    for (; i < SIZE; i++)
    {
        if (fscanf(file, "%hu %hhu %hhu %hhu %hhu %hhd",
                   &info[i].year,
                   &info[i].month,
                   &info[i].day,
                   &info[i].hour,
                   &info[i].minute,
                   &info[i].t) != 6)
            break;
    }
    return (info + i) - ptr;
}

// записать данные из файла
int AddInfoFromFile(struct sensor info[], int start, const char *filename)
{
    struct sensor *ptr = info;

    // FILE *file = fopen("temperature_small.csv", "r");
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error open file\n");
        return -1;
    }

    int i = start;
    int line_number = 1;
    char line[256];
    int scanned;

    while (fgets(line, sizeof(line), file) && i < SIZE)
    {
        scanned = sscanf(line, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd",
                         &info[i].year,
                         &info[i].month,
                         &info[i].day,
                         &info[i].hour,
                         &info[i].minute,
                         &info[i].t);

        if (scanned != 6)
        {
            // printf("Warning: Incorrect data in line %d: %s", line_number, line);
            printf("Warning: Incorrect data in line %d\n", line_number);
            line_number++;
            continue;
        }

        line_number++;
        i++;
    }

    fclose(file);
    return (info + i) - ptr;
}

// печать
void print(struct sensor *info, int count)
{
    printf("------------------------------------------------\n");
    for (int i = 0; i < count; i++)
    {
        printf("%04u-%02u-%02u %02u:%02u t=%3d\n",
               info[i].year,
               info[i].month,
               info[i].day,
               info[i].hour,
               info[i].minute,
               info[i].t);
    }
    printf("------------------------------------------------\n");
}

// печать 1 структуры
void print_1str(struct sensor info)
{
    printf("------------------------\n");
    printf("%04u-%02u-%02u %02u:%02u t=%3d\n",
           info.year,
           info.month,
           info.day,
           info.hour,
           info.minute,
           info.t);
    printf("------------------------\n");
}

// функция среднемесячная температура
float AverMonthTemp(struct sensor info[], int month, int year)
{
    int count = 0, summ = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (info[i].year == year && info[i].month == month)
        {
            summ += info[i].t;
            count++;
        }
    }
    return count != 0 ? (float)summ / count : 99;
}

// функция минимальной температуры в текущем месяце
int MinMonthTemp(struct sensor info[], int month, int year)
{
    struct sensor temp;
    //    struct sensor temp;
    //    struct sensor *t = &temp;
    AddRecord_1str(&temp, 0, 0, 0, 0, 0, 63);
    for (int i = 0; i < SIZE; i++)
    {
        if (info[i].year == year && info[i].month == month)
        {
            if (info[i].t < temp.t)
                temp = info[i];
        }
    }
    return temp.year ? temp.t : 99;
}

// функция максимальной температуры в текущем месяце
int MaxMonthTemp(struct sensor info[], int month, int year)
{
    struct sensor temp;
    //    struct sensor *t = &temp;
    AddRecord_1str(&temp, 0, 0, 0, 0, 0, -63);
    for (int i = 0; i < SIZE; i++)
    {
        if (info[i].year == year && info[i].month == month)
        {
            if (info[i].t > temp.t)
                temp = info[i];
        }
    }
    return temp.year ? temp.t : 99;
}

// функция годовая статистика
void YearStats(struct sensor info[], int year)
{
    printf("Temp in year %4u\n", year);
    printf("mounth medium   min   max   \n");
    for (int i = 1; i <= 12; i++)
    {
        printf("%2d     ", i);
        printf("%3.2f ", AverMonthTemp(info, i, year));
        printf("  %3d ", MinMonthTemp(info, i, year));
        printf("  %3d \n", MaxMonthTemp(info, i, year));
    }
}

// функция статистики одного месяца
void MonthStats(struct sensor info[], int month, int year)
{
    printf("Temp in year %4u in month %2u\n", year, month);
    printf("%3.2f ", AverMonthTemp(info, month, year));
    printf("  %3d ", MinMonthTemp(info, month, year));
    printf("  %3d \n", MaxMonthTemp(info, month, year));
}

// функция среднегодовая температура
float AverYearTemp(struct sensor info[], int year)
{
    int count = 0, summ = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (info[i].year == year)
        {
            summ += info[i].t;
            count++;
        }
    }
    return count != 0 ? (float)summ / count : 99;
}

// функция минимальная температура за год
int MinYearTemp(struct sensor info[], int year)
{
    struct sensor temp;
    AddRecord_1str(&temp, 0, 0, 0, 0, 0, 63);
    for (int i = 0; i < SIZE; i++)
    {
        if (info[i].year == year)
        {
            if (info[i].t < temp.t)
                temp = info[i];
        }
    }
    return temp.year ? temp.t : 99;
}

// функция максимальная температура за год
int MaxYearTemp(struct sensor info[], int year)
{
    struct sensor temp;
    AddRecord_1str(&temp, 0, 0, 0, 0, 0, -63);
    for (int i = 0; i < SIZE; i++)
    {
        if (info[i].year == year)
        {
            if (info[i].t > temp.t)
                temp = info[i];
        }
    }
    return temp.year ? temp.t : 99;
}

//замена
void changeIJ(struct sensor info[],int i, int j)
{
struct sensor temp;
    temp=info[i];
    info[i]=info[j];
    info[j]=temp;
}

//сортировка по температуре
void SortByT(struct sensor info[],int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (info[i].t>=info[j].t)
            {
                changeIJ(info,i,j);
            }
        }
    }
}

//сравнение даты и времени
int Compare(const void* pa,const void* pb)
{
    struct sensor* a = (struct sensor*) pa;
    struct sensor* b = (struct sensor*) pb;
    if(a->year != b->year)
        return a->year - b->year;
    else if (a->month != b->month)
        return a->month - b->month;
    else if (a->day != b->day)
        return a->day - b->day;
    else if (a->hour != b->hour)
        return a->hour - b->hour;
    else
        return a->minute - b->minute;
}

//сортировка по дате
void SortByDate(struct sensor info[],int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (Compare(info+i,info+j)>0)
            {
                changeIJ(info,i,j);
            }
        }
    }
}