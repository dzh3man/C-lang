 #include <stdio.h>
int main(void) {
	int a, b, c, min;
 	scanf("%d%d%d", &a, &b, &c);
  	min = a;
  	if ((a<b) && (b<c)) 
      printf("YES");	
  	else 
      printf("NO");
  return 0;
}
