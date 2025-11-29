/*
파일명 : 프로그래밍 13주차 과제 12번 문제
내  용 : 당구 사용요금 계산 프로그램.
		 당구 시작시간과 종료시간 그리고 10분당 이용 금액을 입력하면 전체 사용 시간(분으로 환산)과 사용 요금이 계산되는 프로그램을 작성한다.
작성자 : 나영탁
날  짜 : 2025.11.25
10.12.13.15.18
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int tax_rate_by_displacement(int D);
double discount_rate_for_past_year(int Y);

int main()
{
	int displacement = 0;
	int year = 0;

	printf("승용차 세금 계산 program\n"); printf("\n");

	printf("승용차의 배기량(cc)을 입력하고 Enter>");
	scanf("%d", &displacement);

	printf("차 구입후 경과년수를 입력하고 Enter>");
	scanf("%d", &year);
	printf("\n");

	printf("배기량   : %d cc\n", displacement);
	printf("경과년도 : %d 년\n", year);
	printf("세금총액 : %d 원\n", (int)(displacement 
									* tax_rate_by_displacement(displacement) 
									* discount_rate_for_past_year(year)));
}

int tax_rate_by_displacement(int D)
{
	if (D <= 800) return 104;
	else if (D <= 1000) return 130;
	else if (D <= 1600) return 182;
	else if (D <= 2000) return 260;
	else if (D <= 2500) return 286;
	else if (D > 2500) return 286;
}

double discount_rate_for_past_year(int Y)
{
	if (Y < 3) return 1.0;
	else if (Y == 3) return 0.95;
	else if (Y == 4) return 0.9;
	else if (Y == 5) return 0.85;
	else if (Y == 6) return 0.8;
	else if (Y == 7) return 0.75;
	else if (Y == 8) return 0.7;
	else if (Y == 9) return 0.65;
	else if (Y == 10) return 0.6;
	else if (Y == 11) return 0.55;
	else if (Y >= 12) return 0.5;
}