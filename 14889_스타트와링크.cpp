/*
	팀을 N/2명씩 나누고 조합으로 사람의 번호를 고르고 중복 순열로 점수의 합을 구하여 갭의 최소값을 찾기.
	
	개선.
	팀을 나눌때 바로 계산하면 연산 줄어들듯.
	팀이 추가될 때 이전에 추가되었던 사람들과의 시너지를 바로 더하기
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

/* 개선 전
void calculate_gap() {
	int sum_start = 0, sum_link = 0;

	//스타트팀 두 명의 선수의 시너지 합 계산
	for (int i = 0; i < start_team.size(); i++) { 
		for (int j = 0; j < start_team.size(); j++) {
			if (i != j)
				sum_start += map[start_team[i]][start_team[j]];
		}
	}
	
	//링크팀 점수 계산
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
	if (cnt == N / 2) { // 팀편성 완료
		link_team.clear();
		for (int i = 0; i < N; i++) {
			if (!check[i])
				link_team.push_back(i);
		}
		calculate_gap();
		return;
	}

	for (int i = cur; i < N; i++) { // 스타트 팀 구성원 추가하기
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
*/

void sum_synergy(int idx, int sum_start, int sum_link) {
	if (idx == N) { // 종료조건
		if (min_gap > abs(sum_start - sum_link))
			min_gap = abs(sum_start - sum_link);
		return;		
	}

	if (start_team.size() < N / 2) { // 스타트팀 점수 게산
		start_team.push_back(idx);
		int temp_sum = 0;
		for (int i = 0; i < start_team.size() - 1; i++) // 추가된 선수의 시너지 합 더하기
			temp_sum += map[start_team[i]][idx] + map[idx][start_team[i]]; 
		sum_synergy(idx + 1, sum_start + temp_sum, sum_link);
		start_team.pop_back();
	}
	if (link_team.size() < N / 2) { // 링크팀 점수 게산
		link_team.push_back(idx);
		int temp_sum = 0;
		for (int i = 0; i < link_team.size() - 1; i++) // 추가된 선수의 시너지 합 더하기
			temp_sum += map[link_team[i]][idx] + map[idx][link_team[i]];
		sum_synergy(idx + 1, sum_start, sum_link + temp_sum);
		link_team.pop_back();
	}
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

	sum_synergy(0, 0, 0);

	cout << min_gap << "\n";

	return 0;
}
