#include <stdio.h>

int main() {
    int a, b, c;
    
    // Ввод трех чисел
    scanf("%d %d %d", &a, &b, &c);
    
    // Проверка, введены ли числа в порядке возрастания
    if (a < b && b < c) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}

