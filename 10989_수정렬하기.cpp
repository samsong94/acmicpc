/*
	N�� �Է¹޾� ����(sort�� merge sort?)
	=> 10,000,000���� �� 38MB �̹Ƿ� �޸��ʰ�
	=> N�� ������ 1~10000�̹Ƿ� �迭�� �����ؼ� ���� ����ϱ�
	
	ios_base::sync_with_stdio(0); cin.tie(0);
	�̰� ����� ���ʰ� �����ʴ´�. cin, cout�� scanf, printf���� ������
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
