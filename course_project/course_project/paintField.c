#include <stdio.h>
#define SIZE 50

void paint(int field[][SIZE], int size, int first_row[], int first_col[]) {
	printf("\n   ");
	for (int i = 0; i < size; i++)
	{
		printf("%4d", first_row[i]);
	}
	printf("\n   ");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("+---");
		}
		printf("+\n %d ", first_col[i]);
		for (int j = 0; j < size; j++) {
			if (field[i][j] == 0) {
				printf("|   ");
			}
			else {
				printf("|  #");
			}
		}
		printf("|\n   ");
	}
	for (int j = 0; j < size; j++) {
		printf("+---");
	}
	printf("+\n");
}
