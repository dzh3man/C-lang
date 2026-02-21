#include <stdio.h>

int is_prime(int n, int delitel) {
    if (n <= 1) {
        return 0;  // Не простое
    }
    if (delitel * delitel > n) {
        return 1;  // Простое 
    }
    if (n % delitel == 0) {
        return 0;  //не простое
    }
    
    return is_prime(n, delitel + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    
    if (is_prime(n, 2)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
