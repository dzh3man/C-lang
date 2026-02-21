#include <stdio.h>

void reverse_string()
 {  
	 char n;
	 n = getchar();
	 if (n!='.') {
		 reverse_string();
		 putchar(n);
	    }
	}
int main()
 { 
reverse_string();

  }
