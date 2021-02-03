#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, numbers[100];
int result;


int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	result = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++) 
		cin >> numbers[i];

	for (int i = 0; i < N-2; i++) {
		for (int j = i+1; j < N-1; j++) {
			for (int k = j+1; k < N; k++) {
				int temp = numbers[i] + numbers[j] + numbers[k];
				if (temp <= M && temp > result)
					result = temp;
			}
		}
	}

	cout << result;

	return 0;
}