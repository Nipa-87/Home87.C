#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

//Структура типа: dddd - год 4 цифры mm - месяц 2 символа dd - день 2 цифры hh - часы 2 цифры
//mm - минуты 2 цифры temperature - целое число от -99 до 99
#pragma pack(push, 1)
struct sensor
{
    uint16_t year;  //год
    uint8_t month;  //месяц
    uint8_t day;    //день
    uint8_t hour;   //час
    uint8_t minute; //минуты
    int8_t t;       //температура 
};
#pragma pack(pop)

//записать данные 1 раз
void AddRecord(struct sensor info[],int number,uint16_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,int8_t t);

//инициализация
void InitInfo(struct sensor info[], int n);

//записать данные из простого файла
int AddInfoFromFileSimple(struct sensor info[], int start);

//записать данные из файла
int AddInfoFromFile(struct sensor info[], int start, const char *file);

//печать
void print(struct sensor *info, int count);

//функция среднемесячная температура
float AverMonthTemp (struct sensor info[], int month, int year);

//функция минимальной температуры в текущем месяце
int MinMonthTemp (struct sensor info[], int month, int year);

//функция максимальной температуры в текущем месяце
int MaxMonthTemp (struct sensor info[], int month, int year);

//функция годовая статистика
void YearStats (struct sensor info[], int year);

// функция статистики одного месяца
void MonthStats(struct sensor info[], int month, int year);

//функция среднегодовая температура
float AverYearTemp (struct sensor info[], int year);

//функция минимальная температура за год
int MinYearTemp (struct sensor info[], int year);

//функция максимальная температура за год
int MaxYearTemp (struct sensor info[], int year);

//сортировки
void SortByT(struct sensor info[],int n);
void SortByDate(struct sensor info[],int n);

#endif
