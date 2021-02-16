/*
	N번의 집에서 최소값이 되려면 N-1번 최소값으로 계산?
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1000][3]; // 1000개의 집, 3개의 색상 가격(RGB)

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
