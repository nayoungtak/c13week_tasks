/*
파일명 : 프로그래밍 13주차 과제 10번 문제
내용 : 당구 사용요금 계산 프로그램.
	   당구 시작시간과 종료시간 그리고 10분당 이용 금액을 입력하면 전체 사용 시간(분으로 환산)과 사용 요금이 계산되는 프로그램을 작성한다.
작성자 : 나영탁
날짜 : 2025.11.25
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int totaltime(int* hp, int* mp, int eh, int em);	// 이용시간 구하는 함수
int calculation_Money(int total, int money);		// 이용시간에 따른 돈 계산하는 함수


int main()
{
	int hour = 0, minu = 0;				// 시작 시, 분 입력받는 변수
	int ehour = 0, eminu = 0;			// 종료 시, 분 입력받는 변수
	int* thp = &hour;					// 시작 시 포인터
	int* tmp = &minu;					// 시작 분 포인터
	int money = 0;						// 10분당 이용 금액 변수

	printf("당구 24시 사용요금 계산 program\n");
	printf("시작시간 입력(시간 분) : ");
	scanf("%d %d", thp, tmp);
	printf("종료시간 입력(시간 분) : ");
	scanf("%d %d", &ehour, &eminu);
	printf("10분당 이용 금액(원) : ");
	scanf("%d", &money);
	printf("\n");

	// 총 이용시간 구하고 분단위의 값 저장 (thp, tmp에는 총 사용 시/분이 저장됨)
	int total_min = totaltime(thp, tmp, ehour, eminu);

	// 기본 요금 계산 (부가세 미포함)
	int base_fee = calculation_Money(total_min, money);
	// 부가세 계산 (기본 요금의 10%)
	int tax = base_fee / 10;

	// 세금 포함 총액
	int total_money = base_fee + tax;
	// 100원 미만 절삭
	int final_money = (total_money / 100) * 100;


	printf("전체 사용 시간: %d시간 %d분(%3d분)\n", *thp, *tmp, total_min);
	printf("전체 사용 금액: %d*", (int)(total_min / 10));
	printf("%d원+", money);
	printf("부가세(%d원)", tax);
	printf(" = %d원\n", final_money);

	return 0;
}

/*
입력 : 시작 시&분, 종료 시&분
계산 : 종료 시간 - 시작시간
반환 : 포인터로 총 시간 반환, return으로 총시간 분으로 변환한값 반환
*/
int totaltime(int* hp, int* mp, int eh, int em)
{
	int start_min = (*hp) * 60 + (*mp); // 시작 총 분
	int end_min = eh * 60 + em;       // 종료 총 분

	// 자정을 넘겨 사용한 경우를 가정 (예: 23:00 시작, 01:00 종료)
	if (end_min < start_min) {
		end_min += 24 * 60; // 종료 시간에 24시간(1440분)을 더해줌
	}

	int total_min = end_min - start_min; // 총 사용 분

	// 포인터 변수에 총 사용 시간을 시, 분으로 저장
	*hp = total_min / 60;
	*mp = total_min % 60;

	return total_min; // 분단위의 총 이용 시간 반환
}


/*
입력 : 분 변환한 총시간, 10분당 이용 금액
계산 : 총시간의 10분의 값 곱하기 이용 금액
반환 : 사용한 이용 금액
*/
int calculation_Money(int total, int money)
{
	// total/10 * money: 10분 단위로 계산하며, 10분 미만은 버림 처리
	return (total / 10) * money;
}