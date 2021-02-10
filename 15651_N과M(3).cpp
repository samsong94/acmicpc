/*
	(1)check �迭�� �̿��ؼ� ����� ���ڿ� ������� ���� ���� Ȯ���Ͽ� ���������� ����ϱ�. nPm
	(2)�ߺ��Ǵ� ������ ���� nCm
	(3)�ߺ����� N^M

	O(N^M) => �ð����⵵�� Ŭ ���̴�. 
	�ִ�ġ�� 8^8 = 16,777,216 �ΰ�? �ߺ����� �ϰŰ� �׷��� 8! = 40320�ΰ�?

	�ߺ������϶� N^M���� �ִ�ġ 8^8�̴�.

	N�� M(2) ����: 1 <= N <= M <=8
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

void my_permutaion(int cnt) {
	if (M == cnt) { // ��������
		print_result();
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!nums[i]) { // �ϳ���üũ�ϰ� ����Ŀ��� �ǵ�����.
			result.push_back(i);
			my_permutaion(cnt+1);
			result.pop_back();
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
