#include <stdio.h>
#include <string.h>

int main() {
    FILE *input_file, *output_file;
    char str[1001];
    
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        return 1;
    }
    
    fgets(str, sizeof(str), input_file);
    fclose(input_file);
    
    int length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
        length--;
    }
    
    for (int i = 0; i < length; i++) {
        if (str[i] == 'a') str[i] = 'b';
        else if (str[i] == 'b') str[i] = 'a';
        else if (str[i] == 'A') str[i] = 'B';
        else if (str[i] == 'B') str[i] = 'A';
    }
    
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        return 1;
    }
    
    fprintf(output_file, "%s\n", str);
    fclose(output_file);
    
    return 0;
}
