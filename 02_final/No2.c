#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	char name[10];
	int score;
	int rank;
	char npn[10];
};

int main(void)
{
	struct student s[5], tmp; 
	int rank2 = 1;
	printf("Input name and score: \n");
	for (int i = 0; i < 5; i++) { 
		printf("name = ");
		gets(s[i].name);
		printf("score = ");
		scanf("%d%*c", &s[i].score);

	}
	printf("------------before---------------\n");
	printf("%-10s %10s\n", "Name", "Score");
	for (int i = 0; i < 5; i++)
	{
		printf("%-10s %10d\n", s[i].name, s[i].score);
	}
	int max = 100, min = 0; 
	max = s[0].score;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (s[i].score < s[j].score)
			{
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
			
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (rank2 < (5%3)*2)
			strcpy(s[i].npn, "P");
		else strcpy(s[i].npn, "N");
		s[i].rank = rank2++;
	}

	printf("-----------after----------------\n");
	printf("%-10s %10s %10s %10s\n", "Name", "Score", "Ranking", "P/NP");
	for (int i = 0; i < 5; i++)
	{
		
		printf("%-10s %10d %10d %10s\n", s[i].name, s[i].score, s[i].rank, s[i].npn);
	}




	return 0;
}