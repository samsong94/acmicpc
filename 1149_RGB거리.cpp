/*
	N���� ������ �ּҰ��� �Ƿ��� N-1�� �ּҰ����� ���?
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1000][3]; // 1000���� ��, 3���� ���� ����(RGB)

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];

	for (int i = 1; i < N; i++) {
		dp[i][0] += (dp[i - 1][1] - dp[i - 1][2] > 0 ? dp[i - 1][2] : dp[i - 1][1]);
		dp[i][1] += (dp[i - 1][0] - dp[i - 1][2] > 0 ? dp[i - 1][2] : dp[i - 1][0]);
		dp[i][2] += (dp[i - 1][0] - dp[i - 1][1] > 0 ? dp[i - 1][1] : dp[i - 1][0]);
	}

	cout << min(dp[N-1][0], min(dp[N-1][1], dp[N-1][2])) << "\n";
	
	return 0;
}
