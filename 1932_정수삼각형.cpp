/*
	dp[N][c]의 최대값 = max(dp[N-1][c-1], dp[N-1][c]) 이다.
	이때 양 끝값은 바로 윗 행의 끝 값으로 정해진다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = 0;
int dp[500][500];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			cin >> dp[i][j];
		
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				dp[i][j] += dp[i - 1][j];
			else if (j == i)
				dp[i][j] += dp[i - 1][j - 1];
			else {
				dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
			}
		}
	}

	ans = 0;
	for (int i = 0; i < N; i++)
		if (ans < dp[N - 1][i])
			ans = dp[N - 1][i];

	cout << ans << "\n";	
	
	return 0;
}
