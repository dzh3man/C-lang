#include <stdio.h>
int main(void)
 { 
	int a, sum = 0,temp; 
	scanf ("%d", &a); 
	 while (a > 0) {
			temp = a;
            temp %= 10;
            sum+=temp; 
            a=a/10; 
            }
    printf("%d\n", sum);
}
