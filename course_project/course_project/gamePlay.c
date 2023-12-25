#include <stdio.h>
#define SIZE 50

int game(int field[][SIZE], int size, int correct_field[][SIZE], int first_row[], int first_col[], char* name_file, int raund) {
	int choice;
	int countString = 0;
	int countColumn = 0;
	int row, col, i;
	printf("\n���������� ������ : %d\n", raund);
	do {
		printf("\n������� ����� ������ -> ");
		scanf("%d", &row);
		printf("\n������� ����� ������� -> ");
		scanf("%d", &col);
		field[row - 1][col - 1] = 1;
		for (i = 0; i < size; i++) {
			if (checkColoumn(field, size, i, first_row[i]) == 1 && checkString(field, size, i, first_col[i]) == 1) {
				countColumn++; // ��������� ��� ������� ���� �� ��������
				countString++; // ���������� ������
			}
		}
		if (countColumn == size && countString == size && checkTwo(row - 1, col - 1, field, size, correct_field) == 1) { 
			// ���� ��� ������� � ���� ������ ��������, � ����� ����������� ������ ������������� ����������� ����, �������� ���
			paint(field, size, first_row, first_col);
			int win = 0;
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (field[i][j] == 1) { // ������� ����������� ������������� ������
						win++;
					}
				}
			}
			if (win == size * 2) { // ���� ���������� ����������� ������ ��������� ���� ������� � ����������� ����������� ����, ���� ������� � ������� ���� � ���������� � ������
				puts("\n*****************");    
				printf("* VICTORY!!!!!! *");                     
				puts("\n*****************");
				break;
			}
			else // ����� ���� ��� �� �����������, ������� ������� ������������ ��������� � ���������� ������
			{
				printf("\n* ������ �����! * ");
			}
		}
		else // ���� ���� �� ������ ��������, ������� ����������� ������ � ��������� ���������� ������
		{
			field[row - 1][col - 1] = 0;
			raund--;
			printf("\n���������� ������ : %d\n\n", raund);
			if (raund == 0) { // ���� ����� ���������, ���� ������� � ������� ���� � ���������� � ���������
				puts("***************");
				printf("* GAME OVER;( *");
				puts("\n***************");
				break;
			}
		}
		countColumn = 0; // �������� ������� ���������� ��������
		countString = 0; // ���������� �������� ������
		printf("������� ����� �������, ����� ����������, ��� ESC ��� ������ � ��������� ����...\n");
		if (getch() == 27) { // ���� ������������, ���� ������������ �� ������ ESC
			printf("\n* �� ������ �� ��������� ����? *\n\n [1] - ��\n [2] - ���\n\n�������� ����� -> ");
			scanf("%d", &choice);
			if (choice == 1) {
				record(field, size, name_file); // ��������� ����
				return raund; // ���������� ���������� ������ �� ������, ���� ������������ ����� ���������� ����
			}
			break;
		}
	} while (1);
	return 0; // ��� ���������� ���������� ������ �� ����������
}
