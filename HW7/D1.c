#include <stdio.h>

void rec(int n)
 {  
	  if (n > 1 ) 
	  rec(n-1); 
	  printf("%d ",n);       
	    }
int main(void)
 { 
	int a; 
	scanf ("%d", &a); 
	rec(a);
  }
