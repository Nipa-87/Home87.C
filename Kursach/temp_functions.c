#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 30

#include "temp_functions.h"
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

// функции для работы со stack
// добавление в stack
void push(stack **p, sensor data)
{
    stack *ptmp;
    ptmp = malloc(sizeof(stack));
    ptmp->value = data;
    ptmp->next = *p;
    *p = ptmp;
}

_Bool empty_stack(stack *p)
{
    return p == NULL;
}

sensor pop(stack **p)
{
    stack *ptmp = *p;
    sensor c;
    if (empty_stack(*p))
        // Попытка взять из пустого стека
        exit(1);
    c = ptmp->value;
    *p = ptmp->next;
    free(ptmp);
    return c;
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


// записать данные из файла в stack
int AddInfoFromFileInStack(stack **p, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error open file\n");
        return -1;
    }

    sensor info;
    int line_number = 1;
    char line[256];
    int scanned;

    while (fgets(line, sizeof(line), file))
    {
        scanned = sscanf(line, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd",
                         &info.year,
                         &info.month,
                         &info.day,
                         &info.hour,
                         &info.minute,
                         &info.t);

        if (scanned != 6)
        {
            // printf("Warning: Incorrect data in line %d: %s", line_number, line);
            printf("Warning: Incorrect data in line %d\n", line_number);
            line_number++;
            continue;
        }
        push(p,info);
        line_number++;
    }
    fclose(file);
    return line_number-1;
}

// печать stack с удалением 
void printStackDel(stack **p)
{
    sensor info;
    printf("------------------------------------------------\n");
    //printf("p=%d",p);
    while(*p != NULL)
    {
        info = pop(p);
        printf("%04u-%02u-%02u %02u:%02u t=%3d\n",
               info.year,
               info.month,
               info.day,
               info.hour,
               info.minute,
               info.t);
    }
    printf("------------------------------------------------\n");
}

// очистка stack 
void cleanStack(stack **p)
{
    //printf("\n----------------clean stack---------------------\n");
    while(*p != NULL)
    {
        pop(p);
    }
    //printf("------------------------------------------------\n");
    //printf("                stack clear                     \n");
    //printf("------------------------------------------------\n");
}

// печать stack без удаления 
void printStack(stack *p)
{
    sensor info;
    stack *current = p;
    printf("------------------------------------------------\n");
    while (current != NULL)
    {
        info = current->value;
        current = current->next;
        printf("%04u-%02u-%02u %02u:%02u t=%3d\n",
               info.year,
               info.month,
               info.day,
               info.hour,
               info.minute,
               info.t);
    }
    printf("------------------------------------------------\n");
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

// функция среднемесячная температура+
float AverMonthTemp(stack *p, int month, int year)
{
    sensor info;
    stack *current = p;
    int count = 0, summ = 0;
    while (current != NULL)
    {
        info = current->value;
        current = current->next;
        if (info.year == year && info.month == month)
        {
            summ += info.t;
            count++;
        }
    }
    return count != 0 ? (float)summ / count : 99;
}

// функция минимальной температуры в текущем месяце+
int MinMonthTemp(stack *p, int month, int year)
{
    sensor temp, info;
    stack *current = p;
    AddRecord_1str(&temp, 0, 0, 0, 0, 0, 63);
    while (current != NULL)
    {
        info = current->value;
        current = current->next;
        if (info.year == year && info.month == month)
        {
            if (info.t < temp.t)
                temp = info;
        }
    }
    return temp.year ? temp.t : 99;
}

// функция максимальной температуры в текущем месяце+
int MaxMonthTemp(stack *p, int month, int year)
{
    sensor temp, info;
    stack *current = p;
    AddRecord_1str(&temp, 0, 0, 0, 0, 0, -63);
    while (current != NULL)
    {
        info = current->value;
        current = current->next;
        if (info.year == year && info.month == month)
        {
            if (info.t > temp.t)
                temp = info;
        }
    }
    return temp.year ? temp.t : 99;
}

// функция статистики одного месяца+
void MonthStats(stack *p, int month, int year)
{
    printf("Temp in year %4u in month %2u\n", year, month);
    printf("%3.2f ", AverMonthTemp(p, month, year));
    printf("  %3d ", MinMonthTemp(p, month, year));
    printf("  %3d \n", MaxMonthTemp(p, month, year));
}

// функция годовая статистика+
void YearStats(stack *p, int year)
{
    printf("Temp in year %4u\n", year);
    printf("mounth medium   min   max   \n");
    for (int i = 1; i <= 12; i++)
    {
        printf("%2d     ", i);
        printf("%3.2f ", AverMonthTemp(p, i, year));
        printf("  %3d ", MinMonthTemp(p, i, year));
        printf("  %3d \n", MaxMonthTemp(p, i, year));
    }
}

// функция среднегодовая температура+
float AverYearTemp(stack *p, int year)
{
    sensor temp, info;
    stack *current = p;
    int count = 0, summ = 0;
    while (current != NULL)
    {
        info = current->value;
        current = current->next;
        if (info.year == year)
        {
            summ += info.t;
            count++;
        }
    }
    return count != 0 ? (float)summ / count : 99;
}

// функция минимальная температура за год+
int MinYearTemp(stack *p, int year)
{
    sensor temp, info;
    stack *current = p;
    AddRecord_1str(&temp, 0, 0, 0, 0, 0, 63);
    while (current != NULL)
    {
        info = current->value;
        current = current->next;
        if (info.year == year)
        {
            if (info.t < temp.t)
                temp = info;
        }
    }
    return temp.year ? temp.t : 99;
}

// функция максимальная температура за год+
int MaxYearTemp(stack *p, int year)
{
    sensor temp, info;
    stack *current = p;
    AddRecord_1str(&temp, 0, 0, 0, 0, 0, -63);
    while (current != NULL)
    {
        info = current->value;
        current = current->next;
        if (info.year == year)
        {
            if (info.t > temp.t)
                temp = info;
        }
    }
    return temp.year ? temp.t : 99;
}

//ненужные сортировки для ДЗ
// замена
void changeIJ(struct sensor info[], int i, int j)
{
    struct sensor temp;
    temp = info[i];
    info[i] = info[j];
    info[j] = temp;
}

// сортировка по температуре
void SortByT(struct sensor info[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (info[i].t >= info[j].t)
            {
                changeIJ(info, i, j);
            }
        }
    }
}

// сравнение даты и времени
int Compare(const void *pa, const void *pb)
{
    struct sensor *a = (struct sensor *)pa;
    struct sensor *b = (struct sensor *)pb;
    if (a->year != b->year)
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

// сортировка по дате
void SortByDate(struct sensor info[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (Compare(info + i, info + j) > 0)
            {
                changeIJ(info, i, j);
            }
        }
    }
}