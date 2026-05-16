#include <stdio.h>
void print_numbers_reverse(int n) {
    if (n == 0) {
        return;
    }
    printf("%d ", n);
    print_numbers_reverse(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    print_numbers_reverse(n);
    
    return 0;
}
    
