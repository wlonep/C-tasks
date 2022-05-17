// 23, 32번 줄 if문 오류 및 row, col 바꿔서 넣음. 정상작동하지 않는 코드임.

#include <stdio.h>
#pragma warning(disable:6031)
#pragma warning(disable:6385)

int print_seats(int seats[3][5])
{
	printf("  | 0 1 2 3 4\n--------------\n");
	for (int i = 0; i < 3; i++) {
		printf("%d |", i);
		for (int j = 0; j < 5; j++) {
			printf(" %d", seats[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 1;
}

int reserve(int seats[3][5], int row, int col)
{	
	if (0 <= col <= 2 && 0 <= row <= 4) {
		if (seats[col][row] == 0) return 1;
		else return -1;
	}
	else return -1;
}

int cancel(int seats[3][5], int row, int col)
{
	if (0 <= col <= 2 && 0 <= row <= 4) {
		if (seats[col][row] == 1) return 1;
		else return -1;
	}
	else return -1;
}

int prj3(void)
{
	int select, row, col;
	int seats[3][5] = {		// 열(row): 0, 1, 2, 3, 4
		{0, 0, 0, 0, 0},	// 행(col): 0, 1, 2
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
	};

	do {
		printf("1: 좌석 확인하기\n2: 예약하기\n3: 예약 취소하기\n4: 종료하기\n");
		printf("메뉴를 선택하세요: ");
		scanf("%d", &select);

		printf("\n선택된 메뉴: ");

		switch (select) {
		case 1:
			printf("좌석 확인하기\n\n");
			print_seats(seats);
			break;

		case 2:
			printf("예약하기\n\n");
			printf("예약할 좌석을 입력해 주세요(행 열): ");
			scanf("%d %d", &row, &col);

			if (reserve(seats, row, col) == 1) {
				printf("예약이 완료되었습니다.\n\n");
				seats[col][row] = 1;
				print_seats(seats);
			}
			else printf("예약에 실패하였습니다.\n\n");
			break;

		case 3:
			printf("예약 취소하기\n\n");
			printf("예약을 취소할 좌석을 입력해 주세요: ");
			scanf("%d %d", &row, &col);

			if (cancel(seats, row, col) == 1) {
				printf("예약 취소가 완료되었습니다.\n\n");
				seats[col][row] = 0;
				print_seats(seats);
			}
			else printf("예약 취소에 실패하였습니다.\n\n");
			break;

		case 4:
			break;

		default:
			printf("X\n올바르지 않은 번호입니다.\n\n");
		}

	} while (select != 4);
	printf("종료하기\n\n이용해 주셔서 감사합니다.");
	return 0;
}
