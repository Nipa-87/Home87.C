#include <stdio.h>

int main() {
    int arr[5];
    int sum = 0;
    float average;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    average = (float)sum / 5;
    printf("%.3f\n", average);
    
    return 0;
}

    
