#include <stdio.h>
#pragma warning(disable:6031)

int s0 = 0;
int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;

int print_seats_prj2()
{
	printf("0 1 2 3 4\n----------\n%d %d %d %d %d\n\n", s0, s1, s2, s3, s4);
	return 1;
}

int reserve_prj2(int seat) 
{
	switch (seat) {
	case 0:
		if (s0 != 0) return -1;
		else {
			s0 = 1;
			return 1;
		}
		break;
	case 1:
		if (s1 != 0) return -1;
		else {
			s1 = 1;
			return 1;
		}
		break;
	case 2:
		if (s2 != 0) return -1;
		else {
			s2 = 1;
			return 1;
		}
		break;
	case 3:
		if (s3 != 0) return -1;
		else {
			s3 = 1;
			return 1;
		}
		break;
	case 4:
		if (s4 != 0) return -1;
		else {
			s4 = 1;
			return 1;
		}
		break;

	default:
		return -1;
	}
}

int cancel_prj2(int seat)
{
	switch (seat) {
	case 0:
		if (s0 != 1) return -1;
		else {
			s0 = 0;
			return 1;
		}
		break;
	case 1:
		if (s1 != 1) return -1;
		else {
			s1 = 0;
			return 1;
		}
		break;
	case 2:
		if (s2 != 1) return -1;
		else {
			s2 = 0;
			return 1;
		}
		break;
	case 3:
		if (s3 != 1) return -1;
		else {
			s3 = 0;
			return 1;
		}
		break;
	case 4:
		if (s4 != 1) return -1;
		else {
			s4 = 0;
			return 1;
		}
		break;

	default:
		return -1;
	}
}

int prj2(void)
{
	int select, s, result;

	do {
		printf("1: 좌석 확인하기\n2: 예약하기\n3: 예약 취소하기\n4: 종료하기\n");
		printf("메뉴를 선택하세요: ");
		scanf("%d", &select);

		printf("\n선택된 메뉴: ");

		switch (select) {
		case 1:
			printf("좌석 확인하기\n\n");
			print_seats();
			break;

		case 2:
			printf("예약하기\n\n");
			printf("예약할 좌석을 입력해 주세요: ");
			scanf("%d", &s);

			if (reserve(s) == 1) {
				printf("예약이 완료되었습니다.\n\n");
				print_seats();
			}
			else printf("예약에 실패하였습니다.\n\n");
			break;

		case 3:
			printf("예약 취소하기\n\n");
			printf("예약을 취소할 좌석을 입력해 주세요: ");
			scanf("%d", &s);

			if (cancel(s) == 1) {
				printf("예약 취소가 완료되었습니다.\n\n");
				print_seats();
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
