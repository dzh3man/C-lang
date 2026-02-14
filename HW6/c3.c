#include <stdio.h>

int sr (int a, int b) {
	int rez = (a+b)/2;
	printf("%d", rez);
	return rez;
	
}

int main(void)
 { 
	int a, b; 
	scanf ("%d %d", &a, &b); 
	sr(a,b);
}
