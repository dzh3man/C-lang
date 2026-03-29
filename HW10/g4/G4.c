#include <stdio.h>
#include <string.h>

int main() {
    FILE *input_file, *output_file;
    char word1[101], word2[101];
    int count1[256] = {0};
    int count2[256] = {0};
    
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        return 1;
    }
    
    fscanf(input_file, "%s %s", word1, word2);
    fclose(input_file);
    
    // Считаем символы в каждом слове
    for (int i = 0; i < strlen(word1); i++) {
        count1[(unsigned char)word1[i]]++;
    }
    for (int i = 0; i < strlen(word2); i++) {
        count2[(unsigned char)word2[i]]++;
    }
    
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        return 1;
    }
    
    // Ищем символы, которые есть в обоих словах ровно по одному разу
    int first = 1;
    for (int c = 0; c < 256; c++) {
        if (count1[c] == 1 && count2[c] == 1) {
            if (!first) {
                fprintf(output_file, " ");
            }
            fprintf(output_file, "%c", c);
            first = 0;
        }
    }
    
    fclose(output_file);
    
    return 0;
}
