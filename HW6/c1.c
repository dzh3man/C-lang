#include <stdio.h>

int module(int a) {
    if (a < 0) {
        return -a; 
    } else {
        return a;  
    }
    printf("%d", a);
}

int main(void)
 { 
	int x; 
	scanf ("%d", &x); 
	printf("%d", module(x));
}
