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
    uint8_t second; //секунды
    int8_t t;       //температура 
};
#pragma pack(pop)

/*Создать прототипы (заглушки) функций вывода статистики по каждому месяцу: среднемесячная
температура, минимальная температура в текущем месяце, максимальная температура в текущем
месяце, вывод статистику за год: • среднегодовая температура • минимальная температура •
максимальная температура
*/

//записать данные 1 раз
void AddRecord(struct sensor info[],int number,uint16_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,uint8_t second,int8_t t);

//инициализация
void InitInfo(struct sensor info[], int n);

//записать данные из простого файла
int AddInfoFromFileSimple(struct sensor info[]);

//печать
void print(struct sensor *info, int count);
//печать как на лекции
void print_1(struct sensor info[],int number);

//функция среднемесячная температура
float AverMonthTemp (struct sensor info[], int month, int year);

//функция минимальной температуры в текущем месяце
float MinMonthTemp (struct sensor info[], int month, int year);

//функция максимальной температуры в текущем месяце
float MaxMonthTemp (struct sensor info[], int month, int year);

//функция годовая статистика
float YearStats (struct sensor info[], int year);

//функция среднегодовая температура
float AverYearTemp (struct sensor info[], int year);

//функция минимальная температура за год
float MinYearTemp (struct sensor info[], int year);

//функция максимальная температура за год
float MaxYearTemp (struct sensor info[], int year);

#endif