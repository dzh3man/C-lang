#include <stdio.h>

// Функция для замены
void SwapArr(int *arr,int i,int j)
{
    int temp = arr[i];
    arr[i]   = arr[j];
    arr[j]   = temp;
}

void HalfSort(int* arr, int n)
{	
	int half = n/2;
    for(int i = 0; i < half/2; i++)
    {
               SwapArr(arr,i,half-1-i);
        }
	for(int i = 0; i < half/2; i++)
    {
               SwapArr(arr,half+i,n-1-i);
        }
}   

            

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
    int arr[10];  // Объявляем массив на 5 элементов
    int n = 10;   // Размер массива
    
    Input(arr, n);  // Передаем массив и его размер
	//Print(arr, n);  // Выводим массив
	HalfSort(arr, n);
	Print(arr, n);

    return 0;
}
