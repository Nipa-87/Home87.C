#include <stdio.h>
#include <string.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    char word1[101], word2[101];
    fscanf(input, "%s %s", word1, word2);
    
    int count1[26] = {0}; 
    int count2[26] = {0}; 
  
    for (int i = 0; word1[i] != '\0'; i++) {
        count1[word1[i] - 'a']++;
    }
   
    for (int i = 0; word2[i] != '\0'; i++) {
        count2[word2[i] - 'a']++;
    }
  
    int first = 1;
    for (char c = 'a'; c <= 'z'; c++) {
        int idx = c - 'a';
        if (count1[idx] == 1 && count2[idx] == 1) {
            if (!first) {
                fprintf(output, " ");
            }
            fprintf(output, "%c", c);
            first = 0;
        }
    }
    
    fprintf(output, "\n");
    
    fclose(input);
    fclose(output);
    
    return 0;
}
