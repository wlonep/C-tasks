#include <stdio.h>
#pragma warning(disable:6031)

int hw72(void)
{
	int big, small, remain;
	printf("두개의 정수를 입력하세요(큰수, 작은수): ");
	scanf("%d %d", &big, &small);

	if (small == 0) printf("최대 공약수는 %d입니다.", big);
	else {
		remain = big % small;
		while (remain != 0) {
			big = small;
			small = remain;
			remain = big % small;
		}
		printf("%d %d %d", big, small, remain);
		printf("최대 공약수는 %d입니다.", small);
	}
	return 0;
}