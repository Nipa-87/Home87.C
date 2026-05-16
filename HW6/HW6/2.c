#include <stdio.h>
void print_binary(int n) {
    if (n == 0 || n == 1) {
        printf("%d", n);
        return;
    }
    print_binary(n / 2);
    printf("%d", n % 2);
}

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
    } else {
        print_binary(n);
        printf("\n");
    }
    
    return 0;
}
