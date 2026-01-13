#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ROWS 3
#define COLS 2

void prMat2(double A[][ROWS], int rows);
void prMat(double A[ROWS][COLS]);
void mutMat(double A[ROWS][COLS], double B[COLS][ROWS], double C[ROWS][ROWS]);

int main(void)
{
	double A[ROWS][COLS] = { 1.1, 1.2, 2.1, 2.2 ,3.1, 3.2 };
	double B[COLS][ROWS] = { 1.1, 1.2, 1.3, 2.1, 2.2 , 2.3 };
	double C[ROWS][ROWS] = { 0.0 };
	int r, c;


	prMat(A);
	prMat2(B, 2);
	mutMat(A, B, C);
	prMat2(C, 3);

	return 0;


}

void mutMat(double A[ROWS][COLS], double B[COLS][ROWS], double C[ROWS][ROWS]) {


	int i, j, k;
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < ROWS; j++)
			for (k = 0; k < COLS; k++)
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
}

void prMat(double A[ROWS][COLS]) {
	int r, c;
	for (r = 0; r < 3; r++)
	{
		for (c = 0; c < 2; c++)
			printf("\t%.2lf ", A[r][c]);
		printf("\n");
	}
	printf("---------------------------------\n");
}

void prMat2(double A[][ROWS], int rows) {
	int r, c;
	for (r = 0; r < rows; r++)
	{
		for (c = 0; c < ROWS; c++)
			printf("\t%.2lf ", A[r][c]);
		printf("\n");
	}
	printf("--------------------------------\n");
}