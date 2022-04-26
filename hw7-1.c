#include <stdio.h>
#pragma warning(disable:6031)

int hw71(void)
{	
	int n, i, sum;
	printf("정수를 입력하세요: ");
	scanf("%d", &n);

	sum = 0;
	i = 1;
	while (i <= n) {
		if (i % 2 == 0) sum += i;
		i += 1;
	}
	printf("1부터 %d까지의 짝수합은 %d입니다.", n, sum);
	return 0;
}