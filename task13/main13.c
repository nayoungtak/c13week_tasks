/*
파일명 : 프로그래밍 13주차 과제 13번 문제
내  용 : 한국전력공사의 전기요금은 기본요금과 사용량에 따른 요금을 합하여 계산한다.
		 기본요금 산정은 [표 1]을, 사용량에 따른 요금 산정은 [표 2]를 기준으로 한다.
		 이러한 기준으로 한 달 전력 사용량에 대해 청구 요금을 계산하여 청구서를 출력하는 프로그램을 작성해라.
작성자 : 나영탁
날  짜 : 2025.11.29
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int get_base_rate(int w);
double get_usage_charge(int w);
int get_surtax(int m);
int electricity_based_fund(int m);


int main()
{
	int W = 0;

	printf("전기요금 청구서 출력 program\n\n");
	printf("전력사용량(Kw/h)을 입력하고 Enter>");
	if (scanf("%d", &W) != 1 || W < 0) {
		printf("잘못된 입력입니다. 전력사용량은 0 이상의 정수여야 합니다.\n");
		return 1; // 오류 종료
	}
	printf("\n");

	// 기본 요금 계산
	int base_rate = get_base_rate(W);
	// 사용 요금 계산
	int usage_charge = (int)round(get_usage_charge(W)); // 사용 요금은 소수점 첫째 자리에서 반올림하여 원 단위로 계산
	// 전력 요금 (기본요금 + 사용 요금)
	int total_electricity_charges = base_rate + usage_charge;
	// 부가세 계산
	int surtax_charge = get_surtax(total_electricity_charges);
	// 전력기반기금 계산
	int fund_charge = electricity_based_fund(total_electricity_charges);
	// 청구 요금 = 전력요금 + 부가가치세 + 전력기금 최종 청구 금액은 10원 미만 절사
	int billing_charges = (int)floor((total_electricity_charges + surtax_charge + fund_charge) / 10.0) * 10;

	// 청구서 출력
	printf("기본요금 : %8d원\n", base_rate);
	printf("사용요금 : %8d원\n", usage_charge);
	printf("전력요금 : %8d원\n", total_electricity_charges);
	printf("전력기금 : %8d원\n", fund_charge);
	printf("부가가치 : %8d원\n", surtax_charge);
	printf("청구요금 : %8d원\n", billing_charges);

	return 0;
}

/*
* 입력 : 전력 사용량 (kWh)
* 처리 : 사용량(w)에 따른 기본 요금을 계산합니다.
* 출력 : 기본 요금 (원)
*/
int get_base_rate(int w)
{
	if (w < 0) return -1; // 음수 사용량은 오류 처리

	// w 값의 범위에 따른 기본 요금 반환
	if (w <= 100) return 390;
	else if (w <= 200) return 870;
	else if (w <= 300) return 1530;
	else if (w <= 400) return 3680;
	else if (w <= 500) return 6970;
	else return 12350;

}

/*
* 입력 : 전력 사용량 (kWh)
* 처리 : 사용량(w)에 따른 사용 요금을 계산합니다.
* 출력 : 사용 요금, 오류 시 -1.0
*/
double get_usage_charge(int w)
{
	// 주택용 저압 누진 요금 단가 (원/kWh)
	const double usage_charges[] = { 57.9, 120.2, 179.4, 267.8, 398.7, 677.3 };
	const int limit = 100;  // 각 구간별 사용량 (kWh)

	if (w < 0) {
		return -1.0;  // 오류를 명시적으로 반환
	}
	if (w == 0) {
		return 0.0;
	}

	int remaining_w = w;
	double total_charge = 0.0;
	// 각 100kWh씩 누진 적용
	for (int i = 0; i < 5 && remaining_w > 0; i++) {
		int consumed = (remaining_w > limit) ? limit : remaining_w;
		total_charge += (consumed * usage_charges[i]);
		remaining_w -= consumed;
	}

	// 500kWh초과
	if (remaining_w > 0) {
		total_charge += (remaining_w * usage_charges[5]);
	}

	return total_charge;
}

/*
* 입력 : 전력 요금 (기본요금 + 사용요금)
* 처리 : 부가가치세(VAT)를 계산합니다. (전력 요금의 10%, 원 미만 반올림)
* 출력 : 부가가치세 (원)
*/
int get_surtax(int m)
{
	return (int)round(m * 0.1);
}

/*
* 입력 : 전력 요금 (기본요금 + 사용요금)
* 처리 : 전력기반기금을 계산합니다. (전력 요금의 3.7%, 10원 미만 절사)
* 출력 : 전력기반기금 (원)
*/
int electricity_based_fund(int m)
{
	double fund = m * 0.037;
	return (int)floor(fund / 10.0) * 10;
}