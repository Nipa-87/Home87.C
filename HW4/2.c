#include <stdio.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int num;
    scanf("%d", &num);
    
    num = abs(num);
    
    bool seen[10] = {false}; 
    bool hasDuplicate = false;
    
    if (num == 0) {
        hasDuplicate = false; 
    } else {
        while (num > 0) {
            int digit = num % 10;
            
            if (seen[digit]) {
                
                hasDuplicate = true;
                break;
            }
            
            seen[digit] = true;
            num /= 10;
        }
    }
    
    printf(hasDuplicate ? "YES" : "NO");
    
    return 0;
}
