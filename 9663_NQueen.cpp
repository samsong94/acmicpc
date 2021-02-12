/*
	N���� ���� N*N�� �ʿ��� ��� ĭ�� �ϳ��� ��ġ�ϴ� �ùķ��̼�
	�� �࿡ �ϳ��� ��ġ�� �ϰ� ���� ������ �ѱ��
	�� �࿡���� �»��, ���, ���� ���� �����ϴ��� Ȯ��
	N ����� �ݺ�
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
			//������ Ȯ��
			if (queens[i].second == c) {
				check = false;
				break;
			}

			//�¿���� Ȯ��
			if (abs(queens[i].first - r) == abs(queens[i].second - c)) {
				check = false;
				break;
			}
		}

		//������ ���� �� �߰�
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
