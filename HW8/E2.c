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

// Функция для вычисления минимального элемента
int min(int *arr, int n) {
    int t = arr[0];  
    for (int i = 1; i < n; i++) {
        if (arr[i] < t){
			t = arr[i];
			}
    }
    if (t == 0){
		printf("0");}
    return t;  // Возвращаем min
}

int main() {
    int arr[5];  // Объявляем массив на 5 элементов
    int n = 5;   // Размер массива
    
    Input(arr, n);  // Передаем массив и его размер
   // Print(arr, n);  // Выводим массив
    printf("%.d\n", min(arr, n));  // Выводим с 2 знаками
    
    return 0;
}
