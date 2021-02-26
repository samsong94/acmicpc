/*
	(1) LIS(���� ���� ����)
	A �����븦 ������������ �����Ͽ��� �� B �����밡 ���� ū �����ϴ� ������ ���� ã�� ��
	(11053 ���� �� �����ϴ� �κ� ������ ����)

	(2) ���׸�Ʈ Ʈ��
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

	cout << N - ans << "\n"; // ������ ������ �������������� �� ����

	return 0;
}
