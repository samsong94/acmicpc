/*
	1 ~ N-1���� N�϶� �����ϴ� �� �϶� i��° dp[i]�� �ִ밪�̶�� dp[N] = dp[i] + 1
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, ans, dp[1000], numbers[1000];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
		dp[i] = 1;
	}

	

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (numbers[i] > numbers[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	
	ans = 0;
	for (int i = 0; i < N; i++)
		if (ans < dp[i])
			ans = dp[i];

	cout << ans << "\n";

	return 0;
}
