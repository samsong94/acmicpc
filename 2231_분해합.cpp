/*
	�� �ڸ����� �ִ� ũ��� 9
	�ڸ�����ŭ 9�� ����� �־��� ������ 9 * �ڸ�����ŭ�� ���� ������ ����� ã��
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, result;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	bool flag = false;
	int temp_N = N;
	int cnt = 0;
	while (temp_N) {
		temp_N = temp_N / 10;
		cnt++;
	}
	for (int i = N - cnt * 9; i < N; i++) {
		result = i;
		int num = i;
		while (num) {
			result += num % 10;
			num = num / 10;
		}
		if (result == N) {
			flag = true;
			result = i;
			break;
		}
	}
	if (flag)
		cout << result;
	else
		cout << 0;

	return 0;
}
