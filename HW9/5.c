#include <stdio.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    char ch;
  
    while ((ch = fgetc(input)) != EOF) {
    
        if (ch == 'a') {
            ch = 'b';
        } else if (ch == 'b') {
            ch = 'a';
        }
        
        else if (ch == 'A') {
            ch = 'B';
        } else if (ch == 'B') {
            ch = 'A';
        }
        
        fputc(ch, output);
    }
    
    fclose(input);
    fclose(output);
    
    return 0;
}
