#include <stdio.h>

int stepen(int a, int b) {
	int rez = a;
	if (b==0) {
		printf("1");
		}
	else{
		for (int i = 1; i< b; i++){
			rez*=a;	
			}
		printf("%d", rez);
		}
		
}

int main(void)
 { 
	int a, b; 
	scanf ("%d %d", &a, &b); 
	stepen(a,b);
}
