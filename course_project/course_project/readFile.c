#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

void read(int correct_field[][SIZE], int size, char* name_file) {
	FILE* file = fopen(name_file, "r"); // Открываем файл для чтения
	if (file == NULL) {
		printf("\nНе удалось открыть сохраненную игру");
		return;
	}
	for (int i = 0; i <= size && !feof(file); i++) {
		for (int j = 0; j <= size && !feof(file); j++) {
			fscanf(file, "%d", &correct_field[i][j]); // Считываем значения с файла в массив correct_field ( правильное/ готовое поле)
		}
	}
	fclose(file); // Закрываем файл
}