#include <stdio.h>

// Функция для ввода массива
int Input(int* arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return i; 
}

// Функция для вывода массива
void Print(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Функция для вычисления среднего арифметического
float average(int *arr, int n) {
    float sum = 0;  
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum/n;  // Возвращаем среднее как float
}

int main() {
    int arr[5];  // Объявляем массив на 5 элементов
    int n = 5;   // Размер массива
    
    Input(arr, n);  // Передаем массив и его размер
   // Print(arr, n);  // Выводим массив
    printf("%.3f\n", average(arr, n));  // Выводим с 2 знаками
    
    return 0;
}
