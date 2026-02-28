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

// Функция для вывода суммы положительных элементов
void positive_sum(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >0){
			sum+=arr[i];
		}
    }
    printf("%d", sum);
}

// Функция для вычисления минимального элемента и его номера
void min(int *arr, int n) {
    int t = arr[0]; 
    int pos = 0; 
    for (int i = 1; i < n; i++) {
        if (arr[i] < t){
			t = arr[i];
			pos = i;
			}
    }
    printf("%d %d ", pos+1, t);  // Возвращаем min  и pos
}

// Функция для вычисления максимального элемента  и его номера
void max(int *arr, int n) {
    int t = arr[0]; 
    int pos = 0; 
    for (int i = 1; i < n; i++) {
        if (arr[i] > t){
			t = arr[i];
			pos = i;
			}
    }
    printf("%d %d ", pos+1, t);  // Возвращаем max и  pos
}
int main() {
    int arr[10];  // Объявляем массив на 5 элементов
    int n = 10;   // Размер массива
    
    Input(arr, n);  // Передаем массив и его размер
   // Print(arr, n);  // Выводим массив
	positive_sum(arr, n);
 
    
    return 0;
}
