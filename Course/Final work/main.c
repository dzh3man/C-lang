#include "temp_functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

void PrintHelp(void) {
    printf("\n========================================\n");
    printf("  Программа для анализа температурных данных\n");
    printf("========================================\n");
    printf("  Вычисляет статистические показатели по месяцам и году\n");
    printf("  (средняя, минимальная, максимальная температура)\n");
    printf("  из CSV-файла.\n");
    printf("\nИспользование:\n");
    printf("  temperature_app.exe [ключи]\n");
    printf("\nКлючи:\n");
    printf("  -h            Показать эту справку\n");
    printf("  -f <файл>     Указать входной CSV файл для обработки\n");
    printf("  -m <месяц>    Показать статистику только за указанный месяц (1-12)\n");
    printf("\nПримеры:\n");
    printf("  temperature_app.exe -f data.csv\n");
    printf("    Загрузить данные и показать полную статистику\n");
    printf("\n  temperature_app.exe -f data.csv -m 7\n");
    printf("    Показать статистику только за июль\n");
    printf("\nФормат CSV:\n");
    printf("  Год;Месяц;День;Час;Минута;Температура\n");
    printf("  Пример: 2024;1;15;12;30;-5\n");
    printf("========================================\n");
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    
    TemperatureRecord* records = NULL;
    char filename[256] = {0};
    int monthFilter = 0;  // 0 - без фильтра
    int fileExist = 0;
    int recordCount = 0;
    int year = 0;
    
    // Парсинг аргументов командной строки
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            PrintHelp();
            return 0;
        }
        else if (strcmp(argv[i], "-f") == 0) {
            if (i + 1 < argc) {
                strncpy(filename, argv[++i], sizeof(filename) - 1);
                filename[sizeof(filename) - 1] = '\0';
                fileExist = 1;
            } else {
                printf("Ошибка: ключ -f требует указания имени файла\n");
                return 1;
            }
        }
        else if (strcmp(argv[i], "-m") == 0) {
            if (i + 1 < argc) {
                monthFilter = atoi(argv[++i]);
                if (monthFilter < 1 || monthFilter > 12) {
                    printf("Ошибка: номер месяца должен быть от 1 до 12\n");
                    return 1;
                }
            } else {
                printf("Ошибка: ключ -m требует указания номера месяца\n");
                return 1;
            }
        }
        else {
            printf("Ошибка: неизвестный ключ '%s'\n", argv[i]);
            printf("Используйте -h для справки\n");
            return 1;
        }
    }
    
    // Проверка наличия входного файла
    if (!fileExist) {
        printf("Ошибка: не указан входной файл (используйте -f <файл>)\n");
        printf("Используйте -h для справки\n");
        return 1;
    }
    
    // Загрузка данных
    printf("\nЗагрузка данных из файла %s...\n", filename);
    recordCount = LoadFromCSV(filename, &records);
    
    if (recordCount == 0) {
        printf("Ошибка: не удалось загрузить ни одной валидной записи\n");
        if (records != NULL) {
            FreeRecords(records);
        }
        return 1;
    }
    
    // Определяем год из первой валидной записи
    for (int i = 0; i < recordCount; i++) {
        if (records[i].isValid) {
            year = records[i].year;
            break;
        }
    }
    
    // Вывод статистики
    if (monthFilter > 0) {
        // Статистика только за указанный месяц
        PrintMonthStatistics(records, recordCount, monthFilter);
    } else {
        // Полная статистика за год
        PrintAllMonthsStatistics(records, recordCount, year);
        PrintYearStatistics(records, recordCount, year);
    }
    
    // Освобождение памяти
    FreeRecords(records);
    
    return 0;
}