#include <stdio.h>
#include <unistd.h>

#include "temp_functions.h"

#define SIZE 30
#define YEARSTAT 2021

int main(int argc, char *argv[])
{

    // ключи (аргумены командной строки)
    int rez = 0;
    opterr = 0;
    const char *filename = "temperature_small.csv";
    int monthFlag = 0;
    int month = 0;
    if (argc == 1)
    {
        printf("This is a program for calculating temperature statistics\n");
        printf("Usage: program [options]\n");
        printf("  -h           This help text\n");
        printf("  -f <file>    Specifying the name of the data file\n");
        printf("               If -f is not specified, default file\n");
        printf("               'temperature_small.csv' will be used\n");
        printf("  -m <month>   Output of statistics for one month\n");
        return 0;
    }
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
            return 0;
            break;
        case 'f':
            // printf("found argument \"f = %s\".\n", optarg);
            filename = optarg;
            break;
        case 'm':
            // printf("found argument \"m = %s\".\n", optarg);
            month = atoi(optarg);
            if (month > 0 && month <= 12)
            {
                monthFlag = 1;
            }
            else
                printf("Error: Month must be between 1 and 12, got '%s'\n", optarg);
            break;
        case '?':
            printf("Error found! Use -h for help.\n");
            break;
        };
    }

    int sizeInput = 0;
    stack *p = NULL;

    // получение данных из файла
    // sizeInput = AddInfoFromFile(info, sizeInput, filename);
    sizeInput = AddInfoFromFileInStack(&p, filename);
    // printf("size %d p=%d\n",sizeInput,p);
    // printStack(p);
    // cleanStack(&p);
    // printStackDel(&p);
    // printStack(p);

    // основной вывод статистики
    if (!monthFlag)
    {
        printf("___________________________________________\n");
        YearStats(p, YEARSTAT);
        printf("___________________________________________\n");
        printf("MediumTemp year %04d = %f\n", YEARSTAT, AverYearTemp(p, YEARSTAT));
        printf("Min temp in year %04d = %d \n", YEARSTAT, MinYearTemp(p, YEARSTAT));
        printf("Max temp in year %04d = %d \n", YEARSTAT, MaxYearTemp(p, YEARSTAT));
        printf("___________________________________________\n");
    }
    else
    {
        printf("___________________________________________\n");
        MonthStats(p, month, YEARSTAT);
        printf("___________________________________________\n");
    }
    cleanStack(&p);
    return 0;
}
