#include <stdio.h>
#include <string.h>
#pragma warning(disable:6031)
#pragma warning(disable:6385)
#define SIZE 10

struct user_info {
	int id_num;
	char id[10];
	char password[10];
};


int load_user_info(struct user_info user[SIZE])
{
	for (int i = 0; i < SIZE; i++) {
		user[i].id_num = (i + 1) * 10;
		sprintf(user[i].id, "user%d", i);
		sprintf(user[i].password, "pass%d", i);
	}
	return 0;
}

int check_login(char id[10], char password[10], struct user_info user[SIZE])
{
	int high, low, mid;
	high = SIZE - 1;
	low = 0;

	while (high >= low) {
		mid = (high + low) / 2;
		int temp = strcmp(id, user[mid].id);
		if (temp > 0) {
			low = mid + 1;
		}
		else if (temp < 0) {
			high = mid - 1;
		}
		else {
			if (strcmp(password, user[mid].password) == 0) return user[mid].id_num;
			else return -2;
		}
	}

	return -1;
}

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

int reserve(int seats[3][5], int row, char col, int id)
{
	int newCol;
	switch (col) {
	case 'A':
		newCol = 0;
		break;
	case 'B':
		newCol = 1;
		break;
	case 'C':
		newCol = 2;
		break;
	default:
		return -1;
	}

	if (0 <= row && row <= 4) {
		if (seats[newCol][row] == 0) {
			seats[newCol][row] = id;
			return 1;
		}
		else return -1;
	}
	else return -1;
}

int cancel(int seats[3][5], int row, char col, int id)
{
	int newCol;
	switch (col) {
	case 'A':
		newCol = 0;
		break;
	case 'B':
		newCol = 1;
		break;
	case 'C':
		newCol = 2;
		break;
	default:
		return -1;
	}

	if (0 <= row && row <= 4) {
		if (seats[newCol][row] == id) {
			seats[newCol][row] = 0;
			return 1;
		}
		else return -1;
	}
	else return -1;
}

int main(void)
{
	char col, pwd[10], id[10];
	int select, row, id_num;
	int seats[3][5] = {		// 행(row): 0, 1, 2, 3, 4
		{0, 0, 0, 0, 0},	// 열(col): A, B, C
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
	};

	struct user_info user[10];
	load_user_info(user);


	do {
		printf("로그인을 해주세요.\n아이디: ");
		scanf("%s", &id);
		printf("비밀번호: ");
		scanf("%s", &pwd);

		switch (check_login(id, pwd, user)) {
		case -1:
			printf("\n일치하는 아이디를 찾을 수 없습니다.\n\n");
			break;
		case -2:
			printf("\n비밀번호가 일치하지 않습니다.\n\n");
			break;
		}
	} while (check_login(id, pwd, user) < 0);

	id_num = check_login(id, pwd, user);


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
			printf("예약할 좌석을 입력해 주세요: ");
			scanf_s("%c%d", &col, 1, &row);

			if (reserve(seats, row, col, id_num) == 1) {
				printf("예약이 완료되었습니다.\n\n");
				print_seats(seats);
			}
			else printf("예약에 실패하였습니다.\n\n");
			break;

		case 3:
			printf("예약 취소하기\n\n");
			printf("예약을 취소할 좌석을 입력해 주세요: ");
			scanf_s("%c%d", &col, 1, &row);

			if (cancel(seats, row, col, id_num) == 1) {
				printf("예약 취소가 완료되었습니다.\n\n");
				print_seats(seats);
			}
			else printf("예약 취소에 실패하였습니다.\n\n");
			break;

		case 4:
			break;

		default:
			printf("X\n올바르지 않은 번호입니다.\n\n");
			break;
		}

	} while (select != 4);

	printf("종료하기\n\n이용해 주셔서 감사합니다.");
	return 0;
}