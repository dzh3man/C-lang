 #include <stdio.h>
int main(void) {
	float x1, y1, x2, y2 , k, b;
 	scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
  	k = (y2-y1)/(x2-x1);
  	b = y1 - k*x1;
	printf("%.2f %.2f",k, b);
  return 0;
}
