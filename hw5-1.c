#include <stdio.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6201)

int hw51(void)
{
	int product, input;
	printf("물건 값을 입력하세요: ");
	scanf("%d", &product);
	printf("사용자가 낸 돈을 입력하세요: ");
	scanf("%d", &input);

	int change = input - product;
	printf("거스름돈: %d원\n", change);

	int moneyArr[8] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };
	for (int i = 0; i < sizeof(moneyArr); i++)
	{
		int count = change / moneyArr[i];
		if (count > 0) printf("%d원: %d개\n", moneyArr[i], count);
		change %= moneyArr[i];
	}

	return 0;
}
