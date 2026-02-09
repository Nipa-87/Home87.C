#include <stdio.h>

int main() {
    int a = 4,  b= 5, c = 7;
    scanf("%f%f%f",&a, &b,&c);
    printf("%f+%f+%f%.2f=%f\n",a,b,c, (a + b + c)/3);
    return 0;
}
