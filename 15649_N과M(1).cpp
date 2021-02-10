/*
	check �迭�� �̿��ؼ� ����� ���ڿ� ������� ���� ���� Ȯ���Ͽ� ���������� ����ϱ�. nPm
	
	O(N^M) => �ð����⵵�� Ŭ ���̴�. 
	�ִ�ġ�� 8^8 = 16,777,216 �ΰ�? �ߺ����� �ϰŰ� �׷��� 8! = 40320�ΰ�?

	N�� M(1) ����: 1 <= N <= M <=8
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
	if (M == cur) { // ��������
		print_result();
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!nums[i]) { // �ϳ���üũ�ϰ� ����Ŀ��� �ǵ�����.
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
