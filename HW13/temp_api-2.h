#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

//Структура типа: dddd - год 4 цифры mm - месяц 2 символа dd - день 2 цифры hh - часы 2 цифры
//mm - минуты 2 цифры temperature - целое число от -99 до 99
#pragma pack(push, 1)
typedef struct sensor
{
    uint16_t year;  //год
    uint8_t month;  //месяц
    uint8_t day;    //день
    uint8_t hour;   //час
    uint8_t minute; //минуты
    int8_t t;       //температура 
} sensor;
#pragma pack(pop)

//тут буду делать stack
typedef struct list 
{
 sensor value;
 struct list * next;
} stack;

//добавление в stack
void push(stack **p,sensor data);

//записать данные 1 раз
void AddRecord(struct sensor info[],int number,uint16_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,int8_t t);

//инициализация
void InitInfo(struct sensor info[], int n);

// записать данные из файла в stack
int AddInfoFromFileInStack(stack **p, const char *filename);

// печать stack с удалением 
void printStackDel(stack **p);

// очистка stack 
void cleanStack(stack **p);

// печать stack без удаления
void printStack(stack *p);

//печать
void print(struct sensor *info, int count);

//функция среднемесячная температура
float AverMonthTemp (stack *p, int month, int year);

//функция минимальной температуры в текущем месяце
int MinMonthTemp (stack *p, int month, int year);

//функция максимальной температуры в текущем месяце
int MaxMonthTemp (stack *p, int month, int year);

//функция годовая статистика
void YearStats (stack *p, int year);

// функция статистики одного месяца
void MonthStats(stack *p, int month, int year);

//функция среднегодовая температура
float AverYearTemp (stack *p, int year);

//функция минимальная температура за год
int MinYearTemp (stack *p, int year);

//функция максимальная температура за год
int MaxYearTemp (stack *p, int year);

//сортировки
void SortByT(struct sensor info[],int n);
void SortByDate(struct sensor info[],int n);

#endif
