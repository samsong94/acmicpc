/*
	N개 입력받아 정렬(sort가 merge sort?)
	=> 10,000,000개는 약 38MB 이므로 메모리초과
	=> N의 범위가 1~10000이므로 배열에 저장해서 전부 출력하기
	
	ios_base::sync_with_stdio(0); cin.tie(0);
	이걸 써줘야 시초가 나지않는다. cin, cout이 scanf, printf보다 느리다
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, number, numbers[10001];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(numbers, 0, sizeof(int));
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> number;
		numbers[number]++;
	}
	for (int i = 1; i <= 10000; i++) {
		for (int cnt = 0; cnt < numbers[i]; cnt++)
			cout << i << "\n";
	}
	return 0;
}
