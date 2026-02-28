#include <stdio.h>

// Функция для замены
void SwapArr(int *arr,int i,int j)
{
    int temp = arr[i];
    arr[i]   = arr[j];
    arr[j]   = temp;
}

// Функция сдвига
void ShiftRight(int* arr, int n, int k) {
    
    int temp[n];  // Временный массив 
    //Сохраняем последние k элементов
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }
	// Сдвигаем остальные элементы вправо
    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }
    
    //Копируем сохраненные элементы в начало
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
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

// Функция для вывода по последней цифре
void BubbleSort(int* arr, int n)
{

    for(int i=0; i<n-1; i++)
    {

        for(int j=0; j<n-i-1; j++)
        {if(arr[j]%10>arr[j+1]%10)
            {
               SwapArr(arr,j,j+1);

            }
        }
    }
  
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
	//ShiftRight(arr, n,4);
	//Print(arr, n);
	BubbleSort(arr, n);
	Print(arr, n);
    return 0;
}
