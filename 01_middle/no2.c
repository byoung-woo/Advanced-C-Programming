#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	double data[12] = { 8.4, 13.7, 15.0, 16.2, 17.4, 18.0, 18.7, 19.0, 19.6, 20.0, 21.0, 21.0};
	double trData[5]; double selected[8];

	double sum = 0.0;
	double avg = 0.0;
	srand((unsigned)time(NULL));


	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 8; i++) {

			selected[i] = data[(rand() % 12)];
			sum += selected[i];
			printf("%10.1lf\t ", selected[i]);

		}
		avg = sum / 8.0;
		trData[j] = avg;
		//printf("sum ::: %.1lf\n", sum);
		sum = 0.0;
		avg = 0.0;
		printf("\n");	
	}
	
	printf("-----trData---------\n");
	for (int j = 0; j < 5; j++) {
		printf("%10.1lf\t", trData[j]);
	}
	
	printf("\n");
	return 0;
}