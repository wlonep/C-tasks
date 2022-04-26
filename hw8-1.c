#include <stdio.h>
#pragma warning(disable:6031)

int get_integer()
{	
	int num;
	printf("숫자를 입력해 주세요: ");
	scanf("%d", &num);
	return num;
}

int factorial(int n)
{
	int result = 1;
	for (n; n > 0; n--) {
		result *= n;
	}
	return result;
}

int combination(int n, int r)
{
	return factorial(n) / (factorial(n - r) * factorial(r));
}

void hw81()
{
	int n = get_integer();
	int r = get_integer();
	printf("%d", combination(n, r));
}