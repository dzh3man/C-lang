#include "temp_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Загрузка данных из CSV файла
int LoadFromCSV(const char* filename, TemperatureRecord** records) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Ошибка: не удалось открыть файл %s\n", filename);
        return 0;
    }
    
    // Первый проход - подсчет количества строк в файле
    char line[1024];
    int totalLines = 0;
    while (fgets(line, sizeof(line), file)) {
        totalLines++;
    }
    
    if (totalLines == 0) {
        printf("Ошибка: файл пуст\n");
        fclose(file);
        return 0;
    }
    
    // Выделяем память под все строки (максимально возможное количество)
    *records = (TemperatureRecord*)malloc(totalLines * sizeof(TemperatureRecord));
    if (*records == NULL) {
        printf("Ошибка: не удалось выделить память для %d записей\n", totalLines);
        fclose(file);
        return 0;
    }
    
    // Второй проход - чтение и парсинг данных
    rewind(file);
    int loaded = 0;
    int lineNum = 0;
    
    while (fgets(line, sizeof(line), file)) {
        lineNum++;
        
        // Пропускаем заголовок если есть
        if (lineNum == 1 && (strstr(line, "YEAR") != NULL || 
            strstr(line, "year") != NULL ||
            strstr(line, "Год") != NULL)) {
            continue;
        }
        
        int year, month, day, hour, minute, temperature;
        
        // Парсим строку (поддерживаем разделители ; и пробелы)
        if (sscanf(line, "%d;%d;%d;%d;%d;%d", 
                   &year, &month, &day, &hour, &minute, &temperature) == 6 ||
            sscanf(line, "%d %d %d %d %d %d", 
                   &year, &month, &day, &hour, &minute, &temperature) == 6) {
            
            // Валидация данных
            int isValid = 1;
            
            if (year < 1900 || year > 2100) {
                printf("Предупреждение: строка %d - некорректный год (%d)\n", lineNum, year);
                isValid = 0;
            }
            if (month < 1 || month > 12) {
                printf("Предупреждение: строка %d - некорректный месяц (%d)\n", lineNum, month);
                isValid = 0;
            }
            if (day < 1 || day > 31) {
                printf("Предупреждение: строка %d - некорректный день (%d)\n", lineNum, day);
                isValid = 0;
            }
            if (hour < 0 || hour > 23) {
                printf("Предупреждение: строка %d - некорректный час (%d)\n", lineNum, hour);
                isValid = 0;
            }
            if (minute < 0 || minute > 59) {
                printf("Предупреждение: строка %d - некорректные минуты (%d)\n", lineNum, minute);
                isValid = 0;
            }
            if (temperature < -99 || temperature > 99) {
                printf("Предупреждение: строка %d - некорректная температура (%d)\n", lineNum, temperature);
                isValid = 0;
            }
            
            // Заполняем структуру
            (*records)[loaded].year = year;
            (*records)[loaded].month = month;
            (*records)[loaded].day = day;
            (*records)[loaded].hour = hour;
            (*records)[loaded].minute = minute;
            (*records)[loaded].temperature = temperature;
            (*records)[loaded].isValid = isValid;
            
            if (isValid) {
                loaded++;
            }
        } else {
            printf("Предупреждение: строка %d - неверный формат (%s)", lineNum, line);
        }
    }
    
    fclose(file);
    
    // Если загружено меньше записей, чем выделено памяти - уменьшаем массив
    if (loaded < totalLines) {
        TemperatureRecord* temp = (TemperatureRecord*)realloc(*records, loaded * sizeof(TemperatureRecord));
        if (temp != NULL || loaded == 0) {
            *records = temp;
        }
    }
    
    printf("Всего строк в файле: %d\n", totalLines);
    printf("Загружено валидных записей: %d\n", loaded);
    printf("Пропущено ошибочных записей: %d\n", totalLines - loaded);
    
    return loaded;
}

// Статистика по месяцу - средняя температура
float MonthAverageTemperature(const TemperatureRecord* records, int recordCount, int month) {
    long long sum = 0;
    int count = 0;
    
    for (int i = 0; i < recordCount; i++) {
        if (records[i].isValid && records[i].month == month) {
            sum += records[i].temperature;
            count++;
        }
    }
    
    if (count > 0) {
        return (float)sum / count;
    }
    return 0.0f;
}

// Статистика по месяцу - минимальная температура
int MonthMinTemperature(const TemperatureRecord* records, int recordCount, int month) {
    int minTemp = INT_MAX;
    int found = 0;
    
    for (int i = 0; i < recordCount; i++) {
        if (records[i].isValid && records[i].month == month) {
            if (records[i].temperature < minTemp) {
                minTemp = records[i].temperature;
            }
            found = 1;
        }
    }
    
    return found ? minTemp : 0;
}

// Статистика по месяцу - максимальная температура
int MonthMaxTemperature(const TemperatureRecord* records, int recordCount, int month) {
    int maxTemp = INT_MIN;
    int found = 0;
    
    for (int i = 0; i < recordCount; i++) {
        if (records[i].isValid && records[i].month == month) {
            if (records[i].temperature > maxTemp) {
                maxTemp = records[i].temperature;
            }
            found = 1;
        }
    }
    
    return found ? maxTemp : 0;
}

// Статистика по году - средняя температура
float YearAverageTemperature(const TemperatureRecord* records, int recordCount, int year) {
    long long sum = 0;
    int count = 0;
    
    for (int i = 0; i < recordCount; i++) {
        if (records[i].isValid && records[i].year == year) {
            sum += records[i].temperature;
            count++;
        }
    }
    
    if (count > 0) {
        return (float)sum / count;
    }
    return 0.0f;
}

// Статистика по году - минимальная температура
int YearMinTemperature(const TemperatureRecord* records, int recordCount, int year) {
    int minTemp = INT_MAX;
    int found = 0;
    
    for (int i = 0; i < recordCount; i++) {
        if (records[i].isValid && records[i].year == year) {
            if (records[i].temperature < minTemp) {
                minTemp = records[i].temperature;
            }
            found = 1;
        }
    }
    
    return found ? minTemp : 0;
}

// Статистика по году - максимальная температура
int YearMaxTemperature(const TemperatureRecord* records, int recordCount, int year) {
    int maxTemp = INT_MIN;
    int found = 0;
    
    for (int i = 0; i < recordCount; i++) {
        if (records[i].isValid && records[i].year == year) {
            if (records[i].temperature > maxTemp) {
                maxTemp = records[i].temperature;
            }
            found = 1;
        }
    }
    
    return found ? maxTemp : 0;
}

// Вывод статистики за указанный месяц
void PrintMonthStatistics(const TemperatureRecord* records, int recordCount, int month) {
    float avg = MonthAverageTemperature(records, recordCount, month);
    int min = MonthMinTemperature(records, recordCount, month);
    int max = MonthMaxTemperature(records, recordCount, month);
    
    // Проверяем, есть ли данные за месяц
    int hasData = 0;
    for (int i = 0; i < recordCount; i++) {
        if (records[i].isValid && records[i].month == month) {
            hasData = 1;
            break;
        }
    }
    
    if (hasData) {
        printf("\n=== Статистика за месяц %02d ===\n", month);
        printf("  Среднемесячная температура: %.2f°C\n", avg);
        printf("  Минимальная температура: %d°C\n", min);
        printf("  Максимальная температура: %d°C\n", max);
    } else {
        printf("\nНет данных за месяц %02d\n", month);
    }
}

// Вывод статистики за год (только итоги)
void PrintYearStatistics(const TemperatureRecord* records, int recordCount, int year) {
    float avg = YearAverageTemperature(records, recordCount, year);
    int min = YearMinTemperature(records, recordCount, year);
    int max = YearMaxTemperature(records, recordCount, year);
    
    int totalRecords = 0;
    for (int i = 0; i < recordCount; i++) {
        if (records[i].isValid && records[i].year == year) {
            totalRecords++;
        }
    }
    
    if (totalRecords > 0) {
        printf("\n=== Статистика за %d год ===\n", year);
        printf("  Всего обработано записей: %d\n", totalRecords);
        printf("  Среднегодовая температура: %.2f°C\n", avg);
        printf("  Минимальная температура за год: %d°C\n", min);
        printf("  Максимальная температура за год: %d°C\n", max);
    } else {
        printf("\nНет данных за %d год\n", year);
    }
}

// Вывод статистики за все месяцы
void PrintAllMonthsStatistics(const TemperatureRecord* records, int recordCount, int year) {
    printf("\n========================================\n");
    printf("        ПОМЕСЯЧНАЯ СТАТИСТИКА\n");
    printf("========================================\n");
    
    for (int month = 1; month <= 12; month++) {
        float avg = MonthAverageTemperature(records, recordCount, month);
        int min = MonthMinTemperature(records, recordCount, month);
        int max = MonthMaxTemperature(records, recordCount, month);
        
        // Проверяем, есть ли данные за месяц
        int hasData = 0;
        int recordsCount = 0;
        for (int i = 0; i < recordCount; i++) {
            if (records[i].isValid && records[i].month == month) {
                hasData = 1;
                recordsCount++;
                break;
            }
        }
        
        if (hasData) {
            printf("\nМесяц %02d (записей: %d):\n", month, recordsCount);
            printf("  Средняя: %.2f°C\n", avg);
            printf("  Мин: %d°C, Макс: %d°C\n", min, max);
            
        }
    }
}

// Освобождение памяти
void FreeRecords(TemperatureRecord* records) {
    if (records != NULL) {
        free(records);
        printf("Память успешно освобождена\n");
    }
}