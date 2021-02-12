/*
	���� N/2�� ������ �������� ����� ��ȣ�� ���� �ߺ� ������ ������ ���� ���Ͽ� ���� �ּҰ��� ã��.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, min_gap;
int map[20][20];
vector<int> start_team, link_team;
bool check[20];

void calculate_gap() {
	int sum_start = 0, sum_link = 0;

	//��ŸƮ�� �� ���� ������ �ó��� �� ���
	for (int i = 0; i < start_team.size(); i++) { 
		for (int j = 0; j < start_team.size(); j++) {
			if (i != j)
				sum_start += map[start_team[i]][start_team[j]];
		}
	}
	
	//��ũ�� ���� ���
	for (int i = 0; i < link_team.size(); i++) {
		for (int j = 0; j < link_team.size(); j++) {
			if (i != j)
				sum_link += map[link_team[i]][link_team[j]];
		}
	}

	if (min_gap > abs(sum_start - sum_link))
		min_gap = abs(sum_start - sum_link);

	return;
}

void make_team(int cur, int cnt) {
	if (cnt == N / 2) { // ���� �Ϸ�
		link_team.clear();
		for (int i = 0; i < N; i++) {
			if (!check[i])
				link_team.push_back(i);
		}
		calculate_gap();
		return;
	}

	for (int i = cur; i < N; i++) { // ��ŸƮ �� ������ �߰��ϱ�
		if (!check[i]) {
			start_team.push_back(i);
			check[i] = true;
			make_team(i + 1, cnt + 1);
			start_team.pop_back();
			check[i] = false;
		}
	}

	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0); 

	min_gap = 99999;
	memset(check, false, sizeof(bool));

	cin >> N;

	for (int r = 0; r < N; r++) 
		for (int c = 0; c < N; c++) 
			cin >> map[r][c];

	make_team(0, 0);

	cout << min_gap << "\n";

	return 0;
}
