#include <stdio.h>
#define SIZE 50

void paint(int field[][SIZE], int size) {
	printf("\n   ");
	for (int i = 1; i <= size; i++)
	{
		printf("%4d", field[0][i]);
	}
	printf("\n   ");
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			printf("+---");
		}
		printf("+\n %d ", field[i][0]);
		for (int j = 1; j <= size; j++) {
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
