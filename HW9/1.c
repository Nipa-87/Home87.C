#include <stdio.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    int N;
    fscanf(input, "%d", &N);
    
    char result[27]; 
    
    int digit = 2;    
    char letter = 'A'; 
    
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
           
            result[i] = digit + '0';
            digit += 2; 
            if (digit > 8) digit = 2; 
        } else {
           
            result[i] = letter;
            letter++; 
        }
    }
    
    result[N] = '\0'; 
    
    fprintf(output, "%s\n", result);
    
    fclose(input);
    fclose(output);
    
    return 0;
}
