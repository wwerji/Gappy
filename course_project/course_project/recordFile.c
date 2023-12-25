#include <stdio.h>
#define SIZE 50

void record(int field[][SIZE], int size, char* name_file) {
    FILE* file = fopen(name_file, "w"); // Открываем файл для записи
    if (file == NULL) {
        printf("Не удалось открыть сохраненную игру\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fprintf(file, "%d ", field[i][j]); // Записываем каждый элемент массива в файл
        }
        fprintf(file, "\n"); // Добавляем перевод строки после каждой строки массива
    }
    fclose(file); // Закрываем файл
    puts("\n**************************");
    printf("* Игра успешно сохранена *");
    puts("\n**************************");
}