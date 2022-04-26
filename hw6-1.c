#include <stdio.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)

int hw61(void)
{
	int year;
	printf("연도를 입력하세요: ");
	scanf("%d", &year);

	if (year % 4 == 0) printf("%d년은 윤년입니다.\n즉, 1년은 366일입니다.", year);
	else printf("%d년은 윤년이 아닙니다.\n즉, 1년은 365일입니다.", year);

	return 0;
}