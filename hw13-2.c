#include <stdio.h>

struct student {
	int number;
	char name[20];
	double grade;
};

struct student get_max_stu(struct student list[3])
{
	struct student super_stu = list[0];
	for (int i = 1; i < 3; i++) {
		if (list[i].grade > super_stu.grade)
			super_stu = list[i];
	}
	return super_stu;
}

int hw132(void)
{
	struct student list[3] = {
		   { 20180001, "홍길동", 3.1 },
		   { 20180002, "김철수", 3.2 },
		   { 20180003, "김영희", 3.9 }
	};
	struct student super_stu;
	super_stu = get_max_stu(list);

	printf("평점이 가장 높은 학생은 (이름%s, 학번%d, 평점%f)입니다\n",
		super_stu.name, super_stu.number, super_stu.grade);
	return 0;
}
