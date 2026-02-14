#include <stdio.h>
int summa(int a){
	int temp = 0;
	for (int i = 0; i <= a; i++)
	{
		temp+=i;}
	return temp;
}
	
int main(void)
 { 
	int x; 
	scanf ("%d", &x); 
	printf("%d", summa(x));
}
