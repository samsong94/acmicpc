/*
	N이 1~40인 경우를 각각 메모이제이션하며 계산하고 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, input, dp[41][2];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	dp[0][0] = 1; dp[0][1] = 0;
	dp[1][0] = 0; dp[1][1] = 1;

	for (int i = 2; i <= 40; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		cout << dp[input][0] << " " << dp[input][1] << "\n";
	}
	return 0;
}
