/*
	(1) LIS(최장 증가 수열)
	A 전봇대를 오름차순으로 정렬하였을 때 B 전봇대가 가장 큰 증가하는 수열의 수를 찾는 것
	(11053 가장 긴 증가하는 부분 수열과 같음)

	(2) 세그먼트 트리
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, ans, dp[100];
vector<pair<int, int>> pole;


int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	int pole_A, pole_B;
	for (int i = 0; i < N; i++) {
		cin >> pole_A >> pole_B;
		pole.push_back(make_pair(pole_A, pole_B));
		dp[i] = 1;
	}

	sort(pole.begin(), pole.end());
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (pole[j].second < pole[i].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	ans = 0;
	for (int i = 0; i < N; i++)
		ans = max(dp[i], ans);

	cout << N - ans << "\n"; // 전깃줄 수에서 최장증가수열의 수 빼기

	return 0;
}
