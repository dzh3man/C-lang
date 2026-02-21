#include <stdio.h>

int summa(int n) 
{
	if (n == 1) 
	{
        return 1;
    }
    return n + summa(n - 1);  // Рекурсивно суммируем
}

int main() {
    int a;
    scanf("%d", &a);
    printf("%d\n", summa(a));
    return 0;
}
