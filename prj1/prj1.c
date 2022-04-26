#include <stdio.h>
#pragma warning(disable:6031)

void loadSeats(int seats[5])
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", i);
	}

	printf("\n----------\n");

	for (int j = 0; j < 5; j++)
	{
		printf("%d ", seats[j]);
	}
	printf("\n\n===============\n");
}

int prj1(void)
{
	int select, reserve;
	int seats[5] = { 0, 0, 0, 0, 0 };

	do {
		printf("1: 좌석 확인하기\n2: 예약하기\n3: 예약 취소하기\n4: 종료하기\n");
		printf("메뉴를 선택하세요: ");
		scanf("%d", &select);

		printf("\n선택된 메뉴: ");

		switch (select) {
		case 1:
			printf("좌석 확인하기\n\n");
			loadSeats(seats);
			break;

		case 2:
			printf("예약하기\n\n");
			printf("예약할 좌석을 입력해 주세요: ");
			scanf("%d", &reserve);

			if (seats[reserve] != 0) printf("이미 예약된 좌석입니다.\n\n");
			else {
				seats[reserve] = 1;
				printf("\n예약이 완료되었습니다.\n\n");
				loadSeats(seats);
			}
			break;

		case 3:
			printf("예약 취소하기\n\n");
			printf("예약을 취소할 좌석을 입력해 주세요: ");
			scanf("%d", &reserve);

			if (seats[reserve] != 1) printf("예약되지 않은 좌석입니다.\n\n");
			else {
				seats[reserve] = 0;
				printf("\n예약 취소가 완료되었습니다.\n\n");
				loadSeats(seats);
			}
			break;
		}

	} while (select != 4);
	printf("종료하기\n\n이용해 주셔서 감사합니다.");
	return 0;
}
