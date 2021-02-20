/*
	2579 계단오르기와 비슷한데 이전 두 잔를 안마시고 스킵하는 경우를 생각.
	dp[i][0] => 이전 두 잔 안 마신경우
	dp[i][1] => 이전 한 잔 안 마신경우
	dp[i][2] => 이전 잔 마신경우
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, ans;
int wine[10000], dp[10000][3];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	ans = 0;
	for (int i = 0; i < N; i++)
		wine[i] = dp[i][0] = dp[i][1] = dp[i][2] = 0;

	for (int i = 0; i < N; i++)
		cin >> wine[i];

	dp[0][0] = dp[0][1] = dp[0][2] = wine[0];
	
	dp[1][0] = wine[1]; 
	dp[1][1] = wine[1]; 
	dp[1][2] = max(dp[0][0], dp[0][1]) + wine[1]; 

	dp[2][0] = wine[2];
	dp[2][1] = max(dp[0][0], max(dp[0][1], dp[0][2])) + wine[2];
	dp[2][2] = max(dp[1][0], dp[1][1]) + wine[2];


	for (int i = 3; i < N; i++) {
		dp[i][0] = max(dp[i - 3][0], max(dp[i - 3][1], dp[i - 3][2])) + wine[i];
		dp[i][1] = max(dp[i - 2][0], max(dp[i - 2][1], dp[i - 2][2])) + wine[i];
		dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + wine[i];
	}

	ans = max(max(dp[N - 2][0], max(dp[N - 2][1], dp[N - 2][2])), max(dp[N - 1][0], max(dp[N - 1][1], dp[N - 1][2])));

	cout << ans << "\n";

	return 0;
}
