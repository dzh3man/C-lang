 #include <stdio.h>
int main(void) {
	int a, max, buf;
 	scanf("%d",&a);
  	max = a%10;
	buf = a%100/10;
  	max = max > buf ? max : buf;
  	buf = a/100;
  	max = max > buf ? max : buf;
	printf("%d",max);
  return 0;
}
