#include <stdio.h>
#include <stdlib.h>

int fumax(int n) {
	int temp = 0;
    if (n < -2) {
       temp = 4;
      // printf("%d\n", temp);
    }
    else if (n >= -2 && n < 2) {
        temp  = n * n;
        //printf("%d\n", temp);
    }
    else { 
        temp =  n * n + 4 * n + 5;
        //printf("%d\n", temp);
    }
    return temp;
}

int main(void) {
    int n;
    int rez = 0;  

    
    while (1) {
        scanf("%d", &n);
        
        if (n == 0) {
            break;
        }

        if (fumax(n) > rez) {
            rez = fumax(n);
        }
	}
	printf("%d", rez);

}


