#include <stdio.h>
#include <unistd.h>

#include "temp_api.h"

#define SIZE 30
#define YEARSTAT 2021

int main(int argc, char *argv[])
{

//ключи (аргумены командной строки)
    int rez = 0;
    opterr = 0;
    const char *filename = "temperature_small.csv";
    int monthFlag = 0;
    int month = 0;
    while ((rez = getopt(argc, argv, "hf:m:")) != -1)
    {
        switch (rez)
        {
        case 'h':
            printf("This is a program for calculating temperature statistics\n");
            printf("Usage: program [options]\n");
            printf("  -h           This help text\n");
            printf("  -f <file>    Specifying the name of the data file\n");
            printf("               If -f is not specified, default file\n");
            printf("               'temperature_small.csv' will be used\n");
            printf("  -m <month>   Output of statistics for one month\n");
            break;
        case 'f':
            //printf("found argument \"f = %s\".\n", optarg);
            filename = optarg;
            break;
        case 'm':
            //printf("found argument \"m = %s\".\n", optarg);
            month = atoi(optarg); 
            if(month > 0 && month <= 12)
                {}
            else
                printf("Error: Month must be between 1 and 12, got '%s'\n", optarg);
            monthFlag = 1;
            break;
        case '?':
            printf("Error found! Use -h for help.\n");
            break;
        };
    }

//структура (объявление и инициализация 0)
    struct sensor info[SIZE];
    InitInfo(info, SIZE);
    int sizeInput = 0;

//получение данных из файла
    sizeInput = AddInfoFromFile(info, sizeInput, filename);
    //printf("%d\n",sizeInput);
    //print(info, sizeInput);
    
//место проб и ошибок
    //SortByT(info, sizeInput); 
    //SortByDate(info, sizeInput);    
    //print(info, sizeInput);

//основной вывод статистики
    if(!monthFlag)
    {
        printf("___________________________________________\n");
        YearStats(info,YEARSTAT);
        printf("___________________________________________\n");
        printf("MediumTemp year %04d = %f\n", YEARSTAT, AverYearTemp(info,YEARSTAT));
        printf("Min temp in year %04d = %d \n", YEARSTAT, MinYearTemp(info,YEARSTAT));
        printf("Max temp in year %04d = %d \n", YEARSTAT, MaxYearTemp(info,YEARSTAT));
        printf("___________________________________________\n");
    }
    else
    {
        printf("___________________________________________\n");
        MonthStats(info, month, YEARSTAT);
        printf("___________________________________________\n");
    }


    return 0;
}
