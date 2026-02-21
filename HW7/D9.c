#include <stdio.h>

int summa(int n) 
{
	if (n < 10) 
	{
        return n;
    }
    return n%10 + summa(n/10);  // Рекурсивно суммируем
}

int main() {
    int a;
    scanf("%d", &a);
    printf("%d\n", summa(a));
    return 0;
}
