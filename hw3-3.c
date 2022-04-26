#include <stdio.h>
#pragma warning(disable:6031)

int hw33(void)
{
	double width;
	double height;

	printf("아래 값들을 입력해주세요.\n사각형의 길이: ");
	scanf("%lf", &width);
	printf("사각형의 높이: ");
	scanf("%lf", &height);

	double area = width * height;
	double circumstance = (width + height) * 2;

	printf("넓이는 %lf 입니다.\n둘레는 %lf 입니다.", area, circumstance);
	return 0;
}