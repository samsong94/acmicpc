/*
	666이 있는지 확인
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, cnt, num, result;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	cnt = 0;
	num = 666;
	while (1) {
		int temp_num = num;
		while (temp_num) {
			if (temp_num % 1000 == 666) {
				cnt++;
				break;
			}
			else
				temp_num = temp_num / 10;
		}
		if (cnt == N)
			break;
		else
			num++;
	}
	
	cout << num;

	return 0;
}
