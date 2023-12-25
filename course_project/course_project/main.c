#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define SIZE 50

void menu();
int raund(int r, int field[][SIZE], int size, int correct_field[][SIZE], int first_row[], int first_col[], char* name_file);

void main() {
	setlocale(LC_ALL, "RUS");
	puts("\n*************************************");
	printf("* «Gappy» - логическая головоломка. *");
	puts("\n*************************************");
	menu();
}

void menu() {
	int choice;
	int r1 = 0;
	int r2 = 0;
	int r3 = 0;
	int r4 = 0;
	int r5 = 0;
	int field[SIZE][SIZE];
	int correct_field[SIZE][SIZE];
	do {
		printf("\nМеню:\n\n [0] - Как играть?\n [1] - Первый уровень\n [2] - Второй уровень\n [3] - Третий уровень\n [4] - Четвертый уровень\n [5] - Пятый уровень\n [6] - Выход из игры\n\nВыберите пункт -> ");
		scanf("%d", &choice);
		if (choice == 6) break;
		switch (choice)
		{
		case 0:
			puts("\n**********************************************************************************************************************");
			printf("  Условие игры:\n\n* - Необходимо расставить черные клетки в сетке так, чтобы в каждом ряду и каждом столбце было по две черные клетки; *\n* - Числа по краям сетки означают количество белых клеток между черными клетками в ряду или столбце.                 *\n");
			puts("\n**********************************************************************************************************************");
			break;
		case 1:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					field[i][j] = 0;
				}
			}
			int first_row_one[4] = { 1, 1, 1, 1 };
			int first_col_one[4] = { 1, 1, 1, 1 };
			read(correct_field, 4, "correct_field_one.txt");
			r1 = raund(r1, field, 4, correct_field, first_row_one, first_col_one, "field_one.txt"); // r1 - это счетчик жизней, если игра продолжается после сохранения
			break;
		case 2:
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					field[i][j] = 0;
				}
			}
			int first_row_two[5] = { 1, 1, 1, 2, 2 };
			int first_col_two[5] = { 2, 2, 1, 1, 1 };
			read(correct_field, 5, "correct_field_two.txt");
			r2 = raund(r2, field, 5, correct_field, first_row_two, first_col_two, "field_two.txt");
			break;
		case 3:
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					field[i][j] = 0;
				}
			}
			int first_row_three[6] = { 2, 1, 4, 1, 1, 3 };
			int first_col_three[6] = { 1, 1, 2, 2, 2, 2 };
			read(correct_field, 6, "correct_field_three.txt");
			r3 = raund(r3, field, 6, correct_field, first_row_three, first_col_three, "field_three.txt");
			break;
		case 4:
			for (int i = 0; i < 7; i++) {
				for (int j = 0; j < 7; j++) {
					field[i][j] = 0;
				}
			}
			int first_row_four[7] = { 5, 1, 3, 3, 2, 2, 1 };
			int first_col_four[7] = { 2, 3, 1, 4, 1, 1, 1 };
			read(correct_field, 7, "correct_field_four.txt");
			r4 = raund(r4, field, 7, correct_field, first_row_four, first_col_four, "field_four.txt");
			break;
		case 5:
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					field[i][j] = 0;
				}
			}
			int first_row_five[9] = { 1, 1, 1, 1, 5, 1, 6, 1, 6 };
			int first_col_five[9] = { 5, 5, 1, 6, 1, 5, 1, 6, 1 };
			read(correct_field, 9, "correct_field_five.txt");
			r5 = raund(r5, field, 9, correct_field, first_row_five, first_col_five, "field_five.txt");
			break;
		}
	} while (1);
}


int raund(int r, int field[][SIZE], int size, int correct_field[][SIZE], int first_row[], int first_col[], char* name_file) { 
	int choice;
	printf("\nХотите продолжить игру или начать новую?\n\n [1] - Продолжить\n [2] - Начать заново\n\nВыберите пункт -> ");
	scanf("%d", &choice);
	if (choice == 2) {
		paint(field, size, first_row, first_col);
		r = game(field, size, correct_field, first_row, first_col, name_file, 5); 
	}
	else if (r == 0) {
		printf("\nУ вас нет сохранённой игры, поэтому она началась заново\n");
		paint(field, size, first_row, first_col);
		r = game(field, size, correct_field, first_row, first_col, name_file, 5);
	}
	else {
		read(field, size, name_file);
		paint(field, size, first_row, first_col);
		r = game(field, size, correct_field, first_row, first_col, name_file, r);
	}
	return r;
}