#include <stdio.h>
#pragma warning(disable:6031)
#pragma warning(disable:6385)
#define SIZE 16

struct user_info {
	int id;
	int password;
};

struct user_info user[SIZE];

int load_user_info()
{
	for (int i = 0; i < SIZE; i++) {
		user[i].id = 10 * (i + 1);
		user[i].password = 4 + 1000 * (i + 1);
	}
	return 0;
}

int check_login(int id, int password)
{
	int low = 0;
	int high = SIZE - 1;
	int median;

	while (low <= high) {
		median = (low + high) / 2;
		if (id == user[median].id) {
			if (password == user[median].password) return id;
			else return -2;
		}
		else if (id > user[median].id) low = median + 1;
		else high = median - 1;
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

int reserve(int seats[3][5], int row, int col, int id)
{
	if (0 <= col && 2 >= col && 0 <= row && row <= 4) {
		if (seats[col][row] == 0) return 1;
		else return -1;
	}
	else return -1;
}

int cancel(int seats[3][5], int row, int col, int id)
{
	if (0 <= col && 2 >= col && 0 <= row && row <= 4) {
		if (seats[col][row] == id) return 1;
		else return -1;
	}
	else return -1;
}

void login(int* id, int* pwd)
{
	int input_id, input_pwd;
	do {
		printf("로그인을 해주세요.\n아이디: ");
		scanf("%d", &input_id);
		printf("비밀번호: ");
		scanf("%d", &input_pwd);

		switch (check_login(input_id, input_pwd)) {
		case -1:
			printf("\n일치하는 아이디를 찾을 수 없습니다.\n\n");
			break;
		case -2:
			printf("\n비밀번호가 일치하지 않습니다.\n\n");
			break;
		}
	} while (check_login(input_id, input_pwd) < 0);

	*id = input_id;
	*pwd = input_pwd;
	printf("\n%d님 반갑습니다.\n\n", input_id);
	return;
}

int prj4(void)
{
	int id, pwd, select, row, col;
	int seats[3][5] = {		// 행(row): 0, 1, 2, 3, 4
		{0, 0, 0, 0, 0},	// 열(col): 0, 1, 2
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
	};

	load_user_info();
	login(&id, &pwd);

	do {
		printf("1: 좌석 확인하기\n2: 예약하기\n3: 예약 취소하기\n4: 종료하기\n5: 로그아웃\n");
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

			if (reserve(seats, row, col, id) == 1) {
				printf("예약이 완료되었습니다.\n\n");
				seats[col][row] = id;
				print_seats(seats);
			}
			else printf("예약에 실패하였습니다.\n\n");
			break;

		case 3:
			printf("예약 취소하기\n\n");
			printf("예약을 취소할 좌석을 입력해 주세요(행 열): ");
			scanf("%d %d", &row, &col);

			if (cancel(seats, row, col, id) == 1) {
				printf("예약 취소가 완료되었습니다.\n\n");
				seats[col][row] = 0;
				print_seats(seats);
			}
			else printf("예약 취소에 실패하였습니다.\n\n");
			break;

		case 4:
			break;

		case 5:
			printf("로그아웃\n\n이용해 주셔서 감사합니다.\n");
			login(&id, &pwd);
			break;

		default:
			printf("X\n올바르지 않은 번호입니다.\n\n");
			break;
		}

	} while (select != 4);
	
	printf("종료하기\n\n이용해 주셔서 감사합니다.");
	return 0;
}