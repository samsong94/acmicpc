/*
	X�� 1, 2, 3 �� ���� ���� 0, 1, 1 �̴�.
	X�� 4�̻��� ��, dp[X]�� ����� X�� �����ϰ� �� ���� ����� dp[i]�� �� ��, dp[i]�� �ּҰ� �Ǵ� �� + 1�̴�.
	dp[X] = min(min((X%3 == 0 ? dp[X/3] : 9999), (X%2 == 0 ? dp[X/2] : 9999)), dp[X-1]) + 1
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int X;
int dp[10000001];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> X;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= X; i++) {
		dp[i] = min(min((i % 3 == 0 ? dp[i / 3] : 99999999), (i % 2 == 0 ? dp[i / 2] : 99999999)), dp[i - 1]) + 1;
	}

	cout << dp[X] << "\n";

	return 0;
}
