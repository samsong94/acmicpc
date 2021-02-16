/*
	끝 자리만 따져서 0 -> 1, 1 -> 0, 3 이런식으로 갯수를 늘려가는 식으로 dp 가능
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long dp[101][10], ans;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	
	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		dp[i][0] += dp[i - 1][1] % 1000000000;
		dp[i][9] += dp[i - 1][8] % 1000000000;
		for (int j = 1; j <= 8; j++) {
			dp[i][j] += dp[i - 1][j - 1] % 1000000000;
			dp[i][j] += dp[i - 1][j + 1] % 1000000000;
		}
	}
	ans = 0;
	for (int i = 0; i < 10; i++)
		ans += dp[N][i] % 1000000000;
	
	cout << ans % 1000000000 << "\n";

	return 0;
}
