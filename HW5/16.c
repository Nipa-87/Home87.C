#include <stdio.h>
unsigned long long grains_on_square(int n) {
    unsigned long long result = 1;
    for (int i = 1; i < n; i++) {
        result *= 2;
    }
    
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%llu\n", grains_on_square(n));
    
    return 0;
}
    
