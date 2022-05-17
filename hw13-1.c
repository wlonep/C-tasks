#include <stdio.h>
#include <math.h>
#pragma warning(disable:6031)

struct point {
	int x;
	int y;
};

int hw131(void)
{
	struct point p1, p2;
	printf("왼쪽 하단의 좌표를 입력하세요: ");
	scanf("%d %d", &p1.x, &p1.y);

	printf("우측 상단의 좌표를 입력하세요: ");
	scanf("%d %d", &p2.x, &p2.y);

	int xdiff = p2.x - p1.x;
	int ydiff = p2.y - p1.y;
	
	printf("면적은 %d이고 둘레는 %d입니다.", xdiff * ydiff, (xdiff + ydiff) * 2);
	return 0;
}