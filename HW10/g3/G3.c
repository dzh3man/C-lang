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
    
	int length = strlen(str);
	if (length > 0 && str[length - 1] == '\n') {
    str[length - 1] = '\0';
    length--;
    }
	char last = str[length - 1];
	
	//printf("str: %s\n", str);
    //printf("length: %d\n", length);
    //printf("last: '%c'\n", last);
	 
	output_file = fopen("output.txt", "w");   
	for (int i = 0; i < length-1; i++) {
	    if (str[i] == last) {  
	        fprintf(output_file, "%d ", i+1);  
	    }
	}
    fclose(output_file);

    
    return 0;
}
