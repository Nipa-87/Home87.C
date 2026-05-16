#include <stdio.h>

int main() {
    int arr[10];
    int max, min;
    int max_index, min_index;
    
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    
    max = arr[0];
    min = arr[0];
    max_index = 0;
    min_index = 0;
    
  
    for (int i = 1; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
        if (arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
    }
    
    printf("%d %d %d %d\n", max_index + 1, max, min_index + 1, min);
    
    return 0;
}

    
