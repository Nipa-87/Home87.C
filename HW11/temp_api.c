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
    uint8_t second; //секунды
    int8_t t;       //температура 
};
*/

//записать данные 1 раз
void AddRecord(struct sensor info[],int number,uint16_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,uint8_t second,int8_t t)
{
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].hour = hour;
    info[number].minute = minute;
    info[number].second = second;
    info[number].t = t;
}

//инициализация
void InitInfo(struct sensor info[], int n)
{
    for(int i=0; i<n; i++)
    {
        AddRecord(info,i,0,0,0,0,0,0,0);
    }
}

//записать данные из простого файла
int AddInfoFromFileSimple(struct sensor info[])
{
    struct sensor *ptr = info;
    
    FILE *file = fopen("SimpleData.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return -1;
    }
    int i=0;
    for(; i<SIZE; i++)
    {
         if(fscanf(file, "%hu %hhu %hhu %hhu %hhu %hhu %hhd",
            &info[i].year,
            &info[i].month,
            &info[i].day,
            &info[i].hour,
            &info[i].minute,
            &info[i].second,
            &info[i].t) != 7)
            break;
    }
    return (info+i)-ptr;
}

//печать
void print(struct sensor *info, int count) 
{
    printf("------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%04d-%02d-%02d %02d:%02d:%02d t=%3d\n",
            info[i].year,
            info[i].month,
            info[i].day,
            info[i].hour,
            info[i].minute,
            info[i].second,
            info[i].t);
    }
}
//печать как на лекции
void print_1(struct sensor info[],int number)
{
    printf("===================================\n");
    for(int i=0;i<number;i++)
        printf("%04d-%02d-%02d t=%3d\n",
        info[i].year,
        info[i].month,
        info[i].day,
        info[i].t);
}

//функция среднемесячная температура
float AverMonthTemp (struct sensor info[], int month, int year)
{

}

//функция минимальной температуры в текущем месяце
float MinMonthTemp (struct sensor info[], int month, int year)
{
    
}

//функция максимальной температуры в текущем месяце
float MaxMonthTemp (struct sensor info[], int month, int year)
{
    
}

//функция годовая статистика
float YearStats (struct sensor info[], int year)
{
    
}

//функция среднегодовая температура
float AverYearTemp (struct sensor info[], int year)
{
    
}

//функция минимальная температура за год
float MinYearTemp (struct sensor info[], int year)
{
    
}

//функция максимальная температура за год
float MaxYearTemp (struct sensor info[], int year)
{
    
}