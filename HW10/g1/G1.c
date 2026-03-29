#include <stdio.h>
#include <string.h>

int main() {
    FILE *input_file, *output_file;
    char str[1000];
    input_file = fopen("input.txt", "r");
    
    if (fgets(str, sizeof(str), input_file) == NULL) {
        printf("Error: input.txt is empty\n");
        fclose(input_file);
        return 1;
    }
    fclose(input_file);
    



    // Создаём output.txt
    output_file = fopen("output.txt", "w");
    fprintf(output_file, "%s, %s, %s %d\n", str, str, str, (int) strlen(str));
    fclose(output_file);

    
    return 0;
}
