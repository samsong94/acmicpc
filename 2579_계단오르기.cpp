/*
	dp[1] = steps[1]
	dp[2] = dp[1]+steps[2]
	dp[3] = steps[1]+steps[2]+steps[3] => 불가능. max(dp[2]+steps[3], dp[1]+steps[3])이다.
	=> dp[n] = max(dp[n-2]+steps[n], steps[n-1]+dp[n])이다.
	
	근데 이때 문제점이 dp[n-1]의 최대값이 dp[n-2] + dp[n-1] 일 수가 있다.
	이전 계단을 선택했는지 확인해야한다.

	dp[n][0]은 이전 계단을 선택하지 않았을 때, dp[n][1]은 이전 계단을 선택했을 때이다.
	dp[1][0] = dp[1][1] = steps[1]
	dp[2][0] = steps[2], dp[2][1] = steps[1] + steps[2]
	...
	dp[n][0] = max(dp[n-2][0], dp[n-2][1]) + steps[n], dp[n][1] = dp[n-1][0] + steps[n]
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, steps[301], dp[301][2];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	cin >> steps[1] >> steps[2];
	for (int i = 3; i <= N; i++)
		cin >> steps[i];
	
	steps[0] = dp[0][0] = dp[0][1] = 0;
	dp[1][0] = dp[1][1] = steps[1];
	for (int i = 2; i <= N; i++) {
		dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + steps[i];
		dp[i][1] = dp[i - 1][0] + steps[i];
	}
	
	cout << max(dp[N][0], dp[N][1]) << "\n";
	return 0;
}
