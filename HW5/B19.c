#include <stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);

   // for (int i = 0; i <= a; i++) {
       int sum = 0;
        //int temp = i;

        while (a > 0) {
            int last = a % 10;      
            sum += last;
            a /= 10; 
        }
      //printf("%d %d\n", sum, mult);

        if (sum == 10) {
            printf("YES");}
         else{
			printf("NO");}
        }
  
