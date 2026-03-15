#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    long long first = 1, second = 1;
    if (n >= 1) {
        printf("%lld", first);
    }
    if (n >= 2) {
        printf(" %lld", second);
    }
    for (int i = 3; i <= n; i++) {
        long long next = first + second;
        printf(" %lld", next);
        first = second;
        second = next;
    }
    
    return 0;
}
 
