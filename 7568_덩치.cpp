/*
	��ü �ð� ���⵵�� N���� N-1�� ����ϹǷ� N^2 => O(N^2), �׸��� N<50�̹Ƿ� 2500
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

	for (int i = 0; i < N; i++) //������, Ű �Է�
		cin >> x[i] >> y[i];

	for (int i = 0; i < N; i++) { // ��� ���
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
