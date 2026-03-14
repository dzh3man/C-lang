int compression(int a[], int b[], int N) {
    int count = 0;  // индекс для массива b
    int current = a[0];  // текущее значение
    int series_length = 1;  // длина серии
    
    // Проверяем начало
    if (a[0] == 1) {
        b[0] = 0;  // первая серия - единицы, записываем 0
        count = 1;
    }
    

    for (int i = 1; i < N; i++) {
        if (a[i] == current) {
            series_length++;  // продолжаем текущую серию
        } else {
            // Записываем длину предыдущей серии
            b[count] = series_length;
            count++;
            
            // Начинаем новую серию
            current = a[i];
            series_length = 1;
        }
    }
    
    // Записываем последнюю серию
    b[count] = series_length;
    count++;
    
    return count; 
}
