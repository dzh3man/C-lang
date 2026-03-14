#include <stdio.h>
#include <string.h>

void count(char number[]) {
    int digit_count[10] = {0} ;
    
    for (int i = 0; number[i]; i++) {
        int digit = number[i] - 48;
        digit_count[digit]++;
    }
    
 
    for (int i = 0; i < 10; i++) {
        if (digit_count[i] > 0) {
            printf("%d %d\n", i, digit_count[i]);
        }
    }
}

int main() {
    char n[1000];  
    scanf("%s", n);
    
    count(n);
    
    return 0;
}
