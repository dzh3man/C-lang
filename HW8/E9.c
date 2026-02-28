#include <stdio.h>

// Функция для замены
void SwapArr(int *arr,int i,int j)
{
    int temp = arr[i];
    arr[i]   = arr[j];
    arr[j]   = temp;
}

// Функция сдвига
void ShiftRight(int* arr, int n) {
    int last = arr[n - 1];  
//сдвиг
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[0] = last;  // Последний элемент ставим в начало
}

void HalfSort(int* arr, int n)
{	
	int third = n/3;
    for(int i = 0; i < third/2; i++)
    {
               SwapArr(arr,i,third-1-i);
        }
	for(int i = 0; i < third/2; i++)
    {
              SwapArr(arr,third+i,n/3*2-1-i);
      }
      	for(int i = 0; i < third/2; i++)
    {
              SwapArr(arr,third*2+i,n-1-i);
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
	ShiftRight(arr, n);
	Print(arr, n);

    return 0;
}
