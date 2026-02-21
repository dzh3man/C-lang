#include <stdio.h>

void rec(int a, int b)
 {  
	 if (a==b){
		printf("%d ",a);
		return;}
	  if (a > b )
	  {
	  printf("%d ",a);    
	  rec(a-1, b); 
	    }
	  else
	  {	  
		rec(a,b-1);
		printf("%d ",b); 
		}
	}
int main(void)
 { 
	int a, b; 
	scanf ("%d %d", &a, &b); 
	rec(a,b);
  }
