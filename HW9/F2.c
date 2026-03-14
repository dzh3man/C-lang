void sort_even_odd(int n, int a[]) {
    int temp[n];  // Временный массив
    int even_index = 0;  // Индекс для четных чисел
    

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {  // Если число четное
            temp[even_index] = a[i];
            even_index++;
        }
    }
    
    // Затем копируем все нечетные элементы
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {  // Если число нечетное
            temp[even_index] = a[i];
            even_index++;
        }
    }
    
    // Копируем обратно в исходный массив
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}
