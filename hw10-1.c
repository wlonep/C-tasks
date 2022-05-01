#include <stdio.h>
#pragma warning(disable:6031)

int hw101(void)
{
	int scores[100];
	int input;
	int count = 0;

	for (int i = 0; i < 100; i++) {
		printf("성적을 입력해 주세요: ");
		scanf("%d", &input);

		if (input < 0) break;
		else {
			scores[i] = input;
			count++;
		}
	}

	int total = 0;

	for (int j = 0; j < count; j++) {
		total += scores[j];
	}
	printf("\n\n평균은 %d 입니다.", total / count);
	return 0;
}