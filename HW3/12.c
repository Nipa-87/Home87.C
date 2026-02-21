
#include <stdio.h>

int main() {
    int number, sum = 0;
    scanf("%d", &number);
    for (; number > 0; number /= 10) {
        sum += number % 10;
    }
    
    printf("%d", sum);
    
    return 0;
}


