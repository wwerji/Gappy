#include <stdio.h>
#define SIZE 50

int game(int field[][SIZE], int size, int correct_field[][SIZE], int first_row[], int first_col[], char* name_file, int raund) {
	int choice;
	int countString = 0;
	int countColumn = 0;
	int row, col, i;
	printf("\nКоличество жизней : %d\n", raund);
	do {
		printf("\nВведите номер строки -> ");
		scanf("%d", &row);
		printf("\nВведите номер столбца -> ");
		scanf("%d", &col);
		field[row - 1][col - 1] = 1;
		for (i = 0; i < size; i++) {
			if (checkColoumn(field, size, i, first_row[i]) == 1 && checkString(field, size, i, first_col[i]) == 1) {
				countColumn++; // Проверяем все столбцы поля по правилам
				countString++; // Аналогично строки
			}
		}
		if (countColumn == size && countString == size && checkTwo(row - 1, col - 1, field, size, correct_field) == 1) { 
			// Если все столбцы и поля прошли проверку, а также закрашенные ячейки соответствуют правильному полю, печатаем его
			paint(field, size, first_row, first_col);
			int win = 0;
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (field[i][j] == 1) { // Считаем закрышенные пользователем клетки
						win++;
					}
				}
			}
			if (win == size * 2) { // Если количество закрашенных клеток исходного поля сошлось с количеством правильного поля, игра выходит в главное меню с сообщением о победе
				puts("\n*****************");    
				printf("* VICTORY!!!!!! *");                     
				puts("\n*****************");
				break;
			}
			else // Иначе игра еще не закончилась, поэтому выводим пользователю сообщение о правильном ответе
			{
				printf("\n* ВЕРНЫЙ ОТВЕТ! * ");
			}
		}
		else // Если поле не прошло проверку, убираем закрашенную ячейку и уменьшаем количество жизней
		{
			field[row - 1][col - 1] = 0;
			raund--;
			printf("\nКоличество жизней : %d\n\n", raund);
			if (raund == 0) { // Если жизни кончились, игра выходит в главное меню с сообщением о проигрыше
				puts("***************");
				printf("* GAME OVER;( *");
				puts("\n***************");
				break;
			}
		}
		countColumn = 0; // Обнуляем счетчик правильных столбцов
		countString = 0; // Аналогично обнуляем строки
		printf("Нажмите любую клавишу, чтобы продолжить, или ESC для выхода в начальное меню...\n");
		if (getch() == 27) { // Игра продолжается, пока пользователь не нажмет ESC
			printf("\n* Вы хотели бы сохранить игру? *\n\n [1] - Да\n [2] - Нет\n\nВыберите пункт -> ");
			scanf("%d", &choice);
			if (choice == 1) {
				record(field, size, name_file); // Сохраняем игру
				return raund; // Возвращаем количество жизней на случай, если пользователь решит продолжить игру
			}
			break;
		}
	} while (1);
	return 0; // Без сохранения количество жизней не возвращаем
}
