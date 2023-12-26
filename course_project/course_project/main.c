#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define SIZE 50

void menu();
int raund(int r, int field[][SIZE], int size, int correct_field[][SIZE], char* name_file);
void fill(int field[][SIZE], int size, int first_row[], int first_col[]);

void main() {
	setlocale(LC_ALL, "RUS");
	puts("\n*************************************");
	printf("* «Gappy» - логическая головоломка. *");
	puts("\n*************************************");
	menu();
}

void menu() {
	int choice;
	int field[SIZE][SIZE];
	int correct_field[SIZE][SIZE];
	int r1 = 0;
	int r2 = 0;
	int r3 = 0;
	int r4 = 0;
	int r5 = 0;
	int first_row_one[4] = { 1, 1, 1, 1 };
	int first_col_one[4] = { 1, 1, 1, 1 };
	int first_row_two[5] = { 1, 1, 1, 2, 2 };
	int first_col_two[5] = { 2, 2, 1, 1, 1 };
	int first_row_three[6] = { 2, 1, 4, 1, 1, 3 };
	int first_col_three[6] = { 1, 1, 2, 2, 2, 2 };
	int first_row_four[7] = { 5, 1, 3, 3, 2, 2, 1 };
	int first_col_four[7] = { 2, 3, 1, 4, 1, 1, 1 };
	int first_row_five[9] = { 1, 1, 1, 1, 5, 1, 6, 1, 6 };
	int first_col_five[9] = { 5, 5, 1, 6, 1, 5, 1, 6, 1 };
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
			fill(field, 4, first_row_one, first_col_one);
			read(correct_field, 3, "correct_field_one.txt");
			r1 = raund(r1, field, 4, correct_field, "field_one.txt"); // r1 - это счетчик жизней, если игра продолжается после сохранения
			break;
		case 2:
			fill(field, 5, first_row_two, first_col_two);
			read(correct_field, 4, "correct_field_two.txt");
			r2 = raund(r2, field, 5, correct_field, "field_two.txt");
			break;
		case 3:
			fill(field, 6, first_row_three, first_col_three);
			read(correct_field, 5, "correct_field_three.txt");
			r3 = raund(r3, field, 6, correct_field, "field_three.txt");
			break;
		case 4:
			fill(field, 7, first_row_four, first_col_four);
			read(correct_field, 6, "correct_field_four.txt");
			r4 = raund(r4, field, 7, correct_field, "field_four.txt");
			break;
		case 5:
			fill(field, 9, first_row_five, first_col_five);
			read(correct_field, 8, "correct_field_five.txt");
			r5 = raund(r5, field, 9, correct_field, "field_five.txt");
			break;
		}
	} while (1);
}


void fill(int field[][SIZE], int size, int first_row[], int first_col[]) {
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			if (i == 0 && j != 0) {
				field[i][j] = first_row[j - 1];
			}
			else if (j == 0 && i != 0) {
				field[i][j] = first_col[i - 1];
			}
			else {
				field[i][j] = 0;
			}
		}
	}
}


int raund(int r, int field[][SIZE], int size, int correct_field[][SIZE], char* name_file) { 
	int choice;
	printf("\nХотите продолжить игру или начать новую?\n\n [1] - Продолжить\n [2] - Начать заново\n\nВыберите пункт -> ");
	scanf("%d", &choice);
	if (choice == 1 && r != 0) {
		read(field, size, name_file);
		paint(field, size);
		r = game(field, size, correct_field, name_file, r);
		return r;
	}
	else if (choice == 1 && r == 0) {
		printf("\nУ вас нет сохранённой игры, поэтому она началась заново\n");
	}
	paint(field, size);
	r = game(field, size, correct_field, name_file, 5);
	return r;
}
