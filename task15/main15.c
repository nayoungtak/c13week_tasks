/*
파일명 : 프로그래밍 13주차 과제 15번 문제
내  용 : 거리에 대한 값과 단위가 입력되면 다음의 도량형 환산표를 기준으로 하여 나머지 단위의 환산 값들을 단위와 함께 출력하는 프로그램을 작성한다.
작성자 : 나영탁
날  짜 : 2025.11.29
18
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	char name[20];
	double Ri;  // 리(里)로 환산하는 비율
} Unit;

Unit conversion_table[9] = {
	{"센티미터", 1.0 / 39277.2},
	{"미터", 1.0 / 392.77},
	{"인치", 1.0 / 15463.3},
	{"피트", 1.0 / 1288.6},
	{"야드", 1.0 / 429.5},
	{"마일", 1.0 / 0.244},
	{"자(척)", 1.0 / 1296.0},
	{"간", 1.0 / 216.0},
	{"리", 1.0}
};

int main()
{
	int value = 0;

	printf("도량형 환산 프로그램\n\n");
	printf("환산값을 입력 : ");
	scanf("%d", &value);
	printf("\n");

	int num = 0;
	printf("단위번호\n");
	printf("0:센티미터	1:미터		2:킬로미터\n");
	printf("3:인치		4:피트		5:야드\n");
	printf("6:마일		7:자(척)	8:간\n9:리\n");
	printf("\n");
	printf("단위번호 선택:");
	if (scanf("%d", &num) != 1 || num < 0 || num > 9) {
		printf("잘못된 입력입니다. 0~9 사이의 숫자를 입력해주세요.\n");
		return 1; // 오류 종료
	}printf("\n");


}