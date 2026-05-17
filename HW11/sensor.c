#include <stdio.h>

#include "temp_api.h"

#define SIZE 30


int main()
{
    //printf("It came alive\n");
    struct sensor info[SIZE];
    InitInfo(info,SIZE);
    int sizeInput = AddInfoFromFileSimple(info);
    //printf("%d\n",sizeInput);
    print(info,sizeInput);
    return 0;
}
