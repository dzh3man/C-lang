#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

// Структура записи температуры
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
    int isValid;  // 1 - запись валидна, 0 - пропущена/ошибочна
} TemperatureRecord;

// Загрузка данных из CSV файла (возвращает количество записей и выделяет память)
int LoadFromCSV(const char* filename, TemperatureRecord** records);

// Статистика по месяцу
float MonthAverageTemperature(const TemperatureRecord* records, int recordCount, int month);
int MonthMinTemperature(const TemperatureRecord* records, int recordCount, int month);
int MonthMaxTemperature(const TemperatureRecord* records, int recordCount, int month);

// Статистика по году
float YearAverageTemperature(const TemperatureRecord* records, int recordCount, int year);
int YearMinTemperature(const TemperatureRecord* records, int recordCount, int year);
int YearMaxTemperature(const TemperatureRecord* records, int recordCount, int year);

// Вывод статистики
void PrintMonthStatistics(const TemperatureRecord* records, int recordCount, int month);
void PrintYearStatistics(const TemperatureRecord* records, int recordCount, int year);
void PrintAllMonthsStatistics(const TemperatureRecord* records, int recordCount, int year);

// Освобождение памяти
void FreeRecords(TemperatureRecord* records);

#endif