/*
	1 ~ 5�� ������ �־�����  ���ĺ��� P(N) = P(N-1) + P(N-5) �̴�.
	��� ���ذ��� ���ڰ� Ŀ���Ƿ� long long �����
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, input;
long long int dp[101];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	dp[1] = 1; dp[2] = 1; dp[3] = 1;  dp[4] = 2; dp[5] = 2;
	
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int i = 6; i <= input; i++)
			dp[i] = dp[i - 1] + dp[i - 5];
		cout << dp[input] << "\n";
	}

	return 0;
}
