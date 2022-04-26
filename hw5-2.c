#include <stdio.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)

int hw52(void)
{
	double f_temp;
	printf("화씨 온도를 입력하세요: ");
	scanf("%lf", &f_temp);

	double c_temp = (f_temp - 32) * 5 / 9;
	printf("섭씨 온도는 %lf입니다.", c_temp);
	return 0;
}