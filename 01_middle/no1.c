#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {


	while (1) {

		char ch;
		double startx = 0.0;
		double stop = 0.0;
		double a = 0.0;

		printf("Input Menu [L: f(x) = a*x H: f(x) = a*x*x+1 S; f(x) = a*sin(x) Q: quit] ? ");
		scanf("%c", &ch);

		if (ch == 'L' || ch == 'l') {
			double x = 0.0;
			double y = 0.0;
			double sum = 0.0;

			printf("Input (a start stop): ");
			scanf("%lf %lf %lf", &a, &startx, &stop);

			for (double i = startx; i <= stop; i += 0.01) {
				x = 0.01;
				y = a * i;
				sum += x * y;
			}

			printf("sum = %lf\n", sum);
		}


		else if (ch == 'H' || ch == 'h') {
			double x = 0.0;
			double y = 0.0;
			double sum = 0.0;

			printf("Input (a start stop): ");
			scanf("%lf %lf %lf", &a, &startx, &stop);

			for (double i = startx; i <= stop; i += 0.01) {
				x = 0.01;
				y = a * i * i + 1;
				sum += x * y;
			}

			printf("sum = %lf\n", sum);

		}

		else if (ch == 'S' || ch == 's') {
			double x = 0.0;
			double y = 0.0;
			double sum = 0.0;

			printf("Input (a start stop): ");
			scanf("%lf %lf %lf", &a, &startx, &stop);

			for (double i = startx; i <= stop; i += 0.01) {
				x = 0.01;
				y = a * (double)sin(i);
				sum += x * y;
			}

			printf("sum = %lf\n", sum);

		}

		else if (ch == 'Q' || ch == 'q') {
			printf("Quit!");
			break;
		}

	}
}



