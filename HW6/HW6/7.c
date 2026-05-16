#include <stdio.h>
void print_prime_factors(int n, int divisor) {
    if (n == 1) {
        return;
    }
    if (n % divisor == 0) {
        printf("%d ", divisor);           
        print_prime_factors(n / divisor, divisor);  
    } else {
     print_prime_factors(n, divisor + 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if (n > 1) {
        print_prime_factors(n, 2);
    }
    
    return 0;
}
    
