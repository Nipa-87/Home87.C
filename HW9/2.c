#include <stdio.h>
#include <string.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    char str[1001];
    fgets(str, 1001, input);

    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
 
    char last_char = str[len - 1];
    int first = 1;
    for (int i = 0; i < len - 1; i++) {
        if (str[i] == last_char) {
            if (!first) {
                fprintf(output, " ");
            }
            fprintf(output, "%d", i + 1); 
            first = 0;
        }
    }
    
    fprintf(output, "\n");
    
    fclose(input);
    fclose(output);
    
    return 0;
}
