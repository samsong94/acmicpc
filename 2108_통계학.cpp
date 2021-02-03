/*
	
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int N, number, result;
int sum, avg, mid, max_cnt, max_cnt_number, cnt, range, max_number, min_number;
int numbers[8001];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(numbers, 0, sizeof(int));
	
	sum = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> number;
		sum += number;
		numbers[number + 4000]++; // -4000 => 0, 4000 => 8000
	}

	// 1. 산술평균	
	//avg = round((double)sum / N);
	if(sum >= 0)
		avg = (int)(((double)sum / N) + 0.5);
	else
		avg = (int)(((double)sum / N) - 0.5);

	// 2. 중앙값
	cnt = 0;
	for (int i = 0; i < 8001; i++) {
		cnt += numbers[i];	

		if (cnt >= (N + 1) / 2) {
			mid = i - 4000;
			break;
		}	
	}

	// 3. 최빈값
	bool check = false;
	max_cnt = 0;
	for (int i = 0; i < 8001; i++) { // 최빈값 찾기
		if (max_cnt < numbers[i])
			max_cnt = numbers[i];
	}
	for (int i = 0; i < 8001; i++) { // 최빈값에 해당하는 숫자 찾기
		if (max_cnt == numbers[i]) {
			if (!check) { // 가장 작은 최빈값의 숫자
				max_cnt_number = i - 4000;
				check = true;
			}
			else { // 두 번째로 작은 최빈값의 숫자
				max_cnt_number = i - 4000;
				break;
			}
		}
	}

	// 4. 범위
	for (int i = 0; i < 8001; i++) { // 최솟값
		if (numbers[i]) {
			min_number = i - 4000;
			break;
		}
	}
	for (int i = 8000; i >= 0; i--) { // 최댓값
		if (numbers[i]) {
			max_number = i - 4000;
			break;
		}
	}

	cout << avg << "\n";
	cout << mid << "\n";
	cout << max_cnt_number << "\n";
	cout << max_number - min_number << "\n";

	return 0;
}
