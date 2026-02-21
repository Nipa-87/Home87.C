#include <stdio.h>

int main() {
    int a, b;
    
    // Ввод двух чисел
    scanf("%d %d", &a, &b);
    
    // Сравнение чисел
    if (a > b) {
        printf("Above\n");
    }
    else if (a < b) {
        printf("Less\n");
    }
    else {
        printf("Equal\n");
    }
    
    return 0;
}
