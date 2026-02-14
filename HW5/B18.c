#include <stdio.h>

void fibonacci(int n) {
 //   if (n <= 0) {
    //    printf("Количество элементов должно быть положительным\n");
   //     return;
  //  }
    
    int a = 1, b = 1, next;
    
    if (n >= 1) {
        printf("%d ", a);
    }
    if (n >= 2) {
        printf("%d ", b);
    }
    
    for (int i = 3; i <= n; i++) {
        next = a + b;
        printf("%d ", next);
        a = b;
        b = next;
    }
    printf("\n");
}

int main() {
    int n;
    
    scanf("%d", &n);
    
	fibonacci(n);
    
    return 0;
}
