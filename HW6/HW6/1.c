#include <stdio.h>
int sum_numbers(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sum_numbers(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", sum_numbers(n));
    
    return 0;
}
