/*
	N개의 퀸을 N*N의 맵에서 모든 칸에 하나씩 배치하는 시뮬레이션
	각 행에 하나씩 배치를 하고 다음 행으로 넘기기
	각 행에서는 좌상단, 상단, 우상단 퀸을 공격하는지 확인
	N 행까지 반복
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, ans;
vector<pair<int, int>> queens;

void simulation(int r) {
	if (r == N) {
		ans++;
		return;
	}

	for (int c = 0; c < N; c++) {
		bool check = true;
		for (int i = 0; i < queens.size(); i++) {
			//세로줄 확인
			if (queens[i].second == c) {
				check = false;
				break;
			}

			//좌우상향 확인
			if (abs(queens[i].first - r) == abs(queens[i].second - c)) {
				check = false;
				break;
			}
		}

		//문제가 없을 시 추가
		if (check) {
			queens.push_back(make_pair(r, c));
			simulation(r + 1);
			queens.pop_back();
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0); 
	
	ans = 0;
	queens.clear();

	cin >> N;

	simulation(0);

	cout << ans << "\n";

	return 0;
}
