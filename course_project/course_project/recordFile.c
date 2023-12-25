#include <stdio.h>
#define SIZE 50

void record(int field[][SIZE], int size, char* name_file) {
    FILE* file = fopen(name_file, "w"); // ��������� ���� ��� ������
    if (file == NULL) {
        printf("�� ������� ������� ����������� ����\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fprintf(file, "%d ", field[i][j]); // ���������� ������ ������� ������� � ����
        }
        fprintf(file, "\n"); // ��������� ������� ������ ����� ������ ������ �������
    }
    fclose(file); // ��������� ����
    puts("\n**************************");
    printf("* ���� ������� ��������� *");
    puts("\n**************************");
}