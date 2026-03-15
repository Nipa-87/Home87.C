#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    if (num == 0) {
        printf("0");
        return 0;
    }
    int reversed = 0;
    while (num > 0) {
        int digit = num % 10;    
        reversed = reversed * 10 + digit; 
        num /= 10;                  
    }
    
    printf("%d", reversed);
    
    return 0;
}
