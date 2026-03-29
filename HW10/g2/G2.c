#include <stdio.h>
#include <string.h>

int main() {
    FILE *input_file, *output_file;
    int N;
    char str[1000];
	int even_digit = 2;  
    char letter = 'A';
    
	input_file = fopen("input.txt", "r");
	if (input_file == NULL) {
		printf("Error: cannot open input.txt\n");
		return 1;
	}

	 if (fscanf(input_file, "%d", &N) != 1) {
		printf("Error: cannot read number from input.txt\n");
		fclose(input_file);
		return 1;
	}
	fclose(input_file);

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {  
            str[i] = letter;  
            letter++;           
        } else { 
			str[i] = '0' + even_digit;
			even_digit += 2;
             if (even_digit > 8)   
                even_digit = 2; 
        }
    }
    str[N] = '\0';
    

    output_file = fopen("output.txt", "w");
    fprintf(output_file, "%s\n", str);
    fclose(output_file);

    
    return 0;
}
