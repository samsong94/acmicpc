/*
	check 배열을 이용해서 사용한 숫자와 사용하지 않은 숫자 확인하여 순차적으로 출력하기. nPm
	
	O(N^M) => 시간복잡도가 클 것이다. 
	최대치는 8^8 = 16,777,216 인가? 중복허용시 일거고 그러면 8! = 40320인가?

	N과 M(1) 범위: 1 <= N <= M <=8
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, M; 
bool nums[9];
vector<int> result;

void print_result() {
	for (unsigned int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
}

void my_permutaion(int cur) {
	if (M == cur) { // 종료조건
		print_result();
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!nums[i]) { // 하나씩체크하고 사용후에는 되돌리기.
			result.push_back(i);
			nums[i] = true; 
			my_permutaion(cur + 1);
			result.pop_back();
			nums[i] = false;
		}
	}
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0); 

	memset(nums, false, sizeof(bool));
	result.clear();

	cin >> N >> M;
	
	my_permutaion(0);
	
	return 0;
}
