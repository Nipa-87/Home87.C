#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    scanf("%d", &num);
    
    num = abs(num);
    
    // Преобразуем число в строку для удобства
    char str[12]; // Достаточно для int
    sprintf(str, "%d", num);
    
    int isAscending = 1;
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] <= str[i-1]) { // Строгое возрастание
            isAscending = 0;
            break;
        }
    }
    
    printf(isAscending ? "YES" : "NO");
    
    return 0;
}
