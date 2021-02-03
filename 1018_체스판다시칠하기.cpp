/*
	1,1 자리가 W인 경우와 B인 경우를 정해서 다시 칠해야 하는 것을 계산해서 비교
	저번에 풀때는 입력을 char말고 string으로 받았고 8*8 잘라서 비교하는데 
	기준이 W, B 일때 각각 바뀌는거 카운트 후 메인에 리턴받고 최소값 체크
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, change;
char map[50][50];

void cnt_wb(int start_r, int start_c) {
	int cnt = 0;
	for (int r = start_r; r < start_r + 8; r++) { // 첫 칸이 B여야 할 때
		for (int c = start_c; c < start_c + 8; c++) {
			if ((r + c) % 2 && map[r][c] == 'W')
				cnt++;
			else if (!((r + c) % 2) && map[r][c] == 'B')
				cnt++;

			if (cnt >= change)
				break;
		}
		if (cnt >= change)
			break;
	}
	if (cnt < change)
		change = cnt;

	cnt = 0;
	for (int r = start_r; r < start_r + 8; r++) { // 첫 칸이 W여야 할 때
		for (int c = start_c; c < start_c + 8; c++) {
			if ((r + c) % 2 && map[r][c] == 'B')
				cnt++;
			else if (!((r + c) % 2) && map[r][c] == 'W')
				cnt++;

			if (cnt >= change)
				break;
		}
		if (cnt >= change)
			break;
	}
	if (cnt < change)
		change = cnt;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	change = 2500;

	cin >> N >> M;
	for (int r = 0; r < N; r++) { // 입력
		for (int c = 0; c < M; c++) {
			cin >> map[r][c];
		}
	}

	for (int r = 0; r < N-7; r++) { // 8*8 찾기
		for (int c = 0; c < M-7; c++) {
			cnt_wb(r, c);
		}
	}

	cout << change;

	return 0;
}
