#include <stdio.h>
#include <string.h>

void count_digits(const char num[], int counts[]) {
    // Инициализируем счетчики нулями
    for (int i = 0; i < 10; i++) {
        counts[i] = 0;
    }
    
    // Подсчитываем количество каждой цифры
    int len = strlen(num);
    for (int i = 0; i < len; i++) {
        int digit = num[i] - '0';
        counts[digit]++;
    }
}

int main() {
    char num[1001]; 
    int counts[10];
    
    scanf("%s", num);
    
    count_digits(num, counts);
    
    for (int digit = 0; digit < 10; digit++) {
        if (counts[digit] > 0) {
            printf("%d %d\n", digit, counts[digit]);
        }
    }
    
    return 0;
}
