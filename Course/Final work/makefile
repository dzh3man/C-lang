# Makefile 
CC = gcc

TARGET = temperature_app.exe 				# target хранит имя исполняемого файла
SOURCES = main.c temp_functions.c				# sources список исходных файлов, к которым обращаемся
OBJECTS = main.o temp_functions.o				# objects список  обьектных файлов, к которым обращаемся
HEADERS = temp_functions.h					# headers список  заголовочных файлов
	
all: $(TARGET) 						# цель all, чтобы выполнить all нужно собрать target

$(TARGET): $(OBJECTS) 					# Цель $(TARGET) (temperature_app.exe). Зависит от $(OBJECTS) # по сути тоже самое gcc -o temperature_app.exe main.o temp_api.o 
	$(CC) -o $(TARGET) $(OBJECTS)			
	@echo "Done!"

main.o: main.c $(HEADERS) 				# Цель main.o. Зависит от main.c и $(HEADERS) (temp_api.h).
	$(CC)  -c main.c -o main.o

temp_api.o: temp_api.c $(HEADERS)			# Цель temp_api.o Зависит от temp_api.c и $(HEADERS) (temp_api.h).
	$(CC)  -c temp_functions.c -o temp_functions.o

clean:							# Очистка собранных файлов # Удаление exe + объектных файлов + сообщений 
	rm $(TARGET) *.o 2>/dev/null				
	@echo "Clean done"

rebuild: clean all 					# Пересборка

run: $(TARGET)
	$(TARGET)

.PHONY: all clean rebuild run	