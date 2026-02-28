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

// Функция для вычисления максимальных 2 элементов
void max_two(int *arr, int n) {
    int max1 = arr[0]; 
    int max2 = arr[1]; 
    if (max1 < max2){
		int t = max1;
		max1 = max2;
		max2 = t;
	}
    
    for (int i = 2; i < n; i++) {
        if (arr[i] > max1){
			max2 = max1;
			max1 = arr[i];
			}
		else if (arr[i] > max2){
			max2 = arr[i];
		}
    }
    printf("%d", max1+max2);  // Возвращаем max1 и  max2
}
int main() {
    int arr[10];  // Объявляем массив на 5 элементов
    int n = 10;   // Размер массива
    
    Input(arr, n);  // Передаем массив и его размер
   // Print(arr, n);  // Выводим массив
   max_two(arr, n);
 
    
    return 0;
}
