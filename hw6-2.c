#include <stdio.h>
#include <math.h>
#pragma warning(disable:6031)

int hw62(void)
{
	int a, b, c;
	printf("a의 계수, b의 계수, c의 계수를 차례대로 입력하세요: ");
	scanf("%d %d %d", &a, &b, &c);
	double discriminant = pow(b, 2.0) - (4 * a * c);

	if (a == 0) {
		double result = -1 * (double) (c / b);
		printf("방정식의 근은 %lf입니다.", result);
	}
	else if (discriminant < 0) printf("실근이 존재하지 않습니다.");
	else {
		double root_1 = (-1 * b + sqrt(discriminant)) / 2 * a;
		double root_2 = (-1 * b - sqrt(discriminant)) / 2 * a;
		printf("방정식의 근은 %lf입니다.\n", root_1);
		if (root_1 != root_2) printf("방정식의 근은 %lf입니다.", root_2);
	}

	return 0;
}