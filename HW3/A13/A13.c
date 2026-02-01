#include <stdio.h>
int main(void)
 { 
	int a , mult; 
	scanf ("%d", &a); 
	mult = a%10;
	mult *= a%100/10;
	mult *= a/100;
	printf ("%d\n",mult );
  }
