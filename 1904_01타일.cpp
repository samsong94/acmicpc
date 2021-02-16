/*
	N이 1씩 커지면 1,2,3,5,8,13,... 피보나치?
	재귀함수는 중복이 많기에 dp사용
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, dp[1000001];

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
		
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) 
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;

	cout << dp[N] << "\n"; 

	return 0;
}
