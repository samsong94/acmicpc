/*
	
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

long long N;
int numbers[10];
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	memset(numbers, 0, sizeof(int));

	cin >> N;

	while (N) {
		numbers[N % 10]++;
		N = N / 10;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < numbers[i]; j++)
			cout << i;
	}

	return 0;
}
