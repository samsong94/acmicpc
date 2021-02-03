/*
	N개 입력받아 정렬(sort가 merge sort?)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, number;
vector<int> numbers;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> number;
		numbers.push_back(number);
	}
	sort(numbers.begin(), numbers.end());

	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << "\n";
	}
	return 0;
}
