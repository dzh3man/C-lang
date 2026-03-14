#include <stdio.h>

int find_missing() {
    int sum_full, sum_input = 0;
    int x;
    int min = 10000, max = 0;
    int count = 0;
    
    scanf("%d", &x);
    while (x != 0) {
        sum_input += x;
        if (x < min) min = x;
        if (x > max) max = x;
        count++;
        scanf("%d", &x);
    }
    
    // Сумма арифметической прогрессии от min до max
    sum_full = (min + max) * (max - min + 1) / 2;
    
    return sum_full - sum_input;
}

int main() {
    int missing = find_missing();
    printf("%d\n", missing);
    return 0;
}
