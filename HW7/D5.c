#include <stdio.h>

void bin(int n) {
    if (n <= 1) {
        printf("%d", n);  // Выводим последнюю цифру
        return;
    }
    bin(n / 2);
    printf("%d", n % 2);
}

int main() {
    int a;
    scanf("%d", &a);
    bin(a);
    printf("\n");
    
    return 0;
}
