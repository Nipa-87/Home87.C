#include <stdio.h>

void print_digit(char s[]) {
    int counts[10] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            counts[s[i] - '0']++;
        }
    }
    
    for (int digit = 0; digit < 10; digit++) {
        if (counts[digit] > 0) {
            printf("%d %d\n", digit, counts[digit]);
        }
    }
}
