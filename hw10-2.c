#include <stdio.h>
#define NUM_EXAM 3
#define NUM_STUDENT 5

int find_min(int score[NUM_EXAM][NUM_STUDENT], int exam) {
	int min = score[exam][0];
	for (int i = 1; i < NUM_STUDENT; i++) {
		if (min > score[exam][i]) min = score[exam][i];
	}
	return min;
}

int find_max(int score[NUM_EXAM][NUM_STUDENT], int exam) {
	int max = score[exam][0];
	for (int i = 1; i < NUM_STUDENT; i++) {
		if (max < score[exam][i]) max = score[exam][i];
	}
	return max;
}

int find_avg(int score[NUM_EXAM][NUM_STUDENT], int exam) {
	int total = 0;
	for (int i = 0; i < NUM_STUDENT; i++) {
		total += score[exam][i];
	}
	return total / NUM_STUDENT;
}

int hw102()
{
	int score[NUM_EXAM][NUM_STUDENT] = {
		{60, 80, 43, 78, 93},
		{75, 59, 81, 77, 81},
		{83, 74, 97, 73, 81}
	};

	for (int i = 0; i < NUM_EXAM; i++) {
		printf("시험 %d\n최소: %d\n최대: %d\n평균: %d\n\n", i, find_min(score, i), 
			find_max(score, i), find_avg(score, i));
	}
	return 0;
}