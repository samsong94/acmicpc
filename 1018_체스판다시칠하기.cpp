/*
	1,1 �ڸ��� W�� ���� B�� ��츦 ���ؼ� �ٽ� ĥ�ؾ� �ϴ� ���� ����ؼ� ��
	������ Ǯ���� �Է��� char���� string���� �޾Ұ� 8*8 �߶� ���ϴµ� 
	������ W, B �϶� ���� �ٲ�°� ī��Ʈ �� ���ο� ���Ϲް� �ּҰ� üũ
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
	for (int r = start_r; r < start_r + 8; r++) { // ù ĭ�� B���� �� ��
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
	for (int r = start_r; r < start_r + 8; r++) { // ù ĭ�� W���� �� ��
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
	for (int r = 0; r < N; r++) { // �Է�
		for (int c = 0; c < M; c++) {
			cin >> map[r][c];
		}
	}

	for (int r = 0; r < N-7; r++) { // 8*8 ã��
		for (int c = 0; c < M-7; c++) {
			cnt_wb(r, c);
		}
	}

	cout << change;

	return 0;
}
