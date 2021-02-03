/*
	전체 시간 복잡도는 N명이 N-1번 계산하므로 N^2 => O(N^2), 그리고 N<50이므로 2500
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, x[50], y[50];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) //몸무게, 키 입력
		cin >> x[i] >> y[i];

	for (int i = 0; i < N; i++) { // 등수 계산
		int rank = 1;
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			if (x[i] < x[j] && y[i] < y[j])
				rank++;
		}
		cout << rank << " ";
	}


	return 0;
}
