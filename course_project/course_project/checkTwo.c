#include <stdio.h>
#define SIZE 50

int checkTwo(int row, int col, int field[][SIZE], int size, int correct_field[][SIZE]) {
	if (field[row][col] == correct_field[row-1][col-1]) { // ���������� ��������� �������� ������������ � ������� ���������� �����
		return 1;
	}
	else {
		puts("\n**************************************");
		printf("* ���������� ��������� ������ ������ *");
		puts("\n**************************************");
		return 0;
	}	
}
