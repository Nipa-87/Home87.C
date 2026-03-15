#include <stdio.h>

int is_sum_of_digits_even(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return (sum % 2 == 0);
}

int main() {
    int number;
    scanf("%d", &number);
    
    if (is_sum_of_digits_even(number)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
