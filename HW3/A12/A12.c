#include <stdio.h>
int main(void)
 { 
	int a , sum ; 
	scanf ("%d", &a); 
	sum = a%10;
	sum += a%100/10;
	sum += a/100;
	printf ("%d\n",sum );
  }
