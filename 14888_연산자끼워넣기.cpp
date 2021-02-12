/*
	숫자는 순서가 그대로.
	연산자는 순서가 랜덤 -> 0,1,2,3을 주어진 수만큼 배열. 순열?
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, numbers[100], oper[4];
int result_min, result_max;

void simulation(int cnt, int result, int add, int sub, int mul, int div) {
	if (cnt == N) { // 최대, 최소 확인
		if (result_min > result)
			result_min = result;
		if (result_max < result)
			result_max = result;
	}

	//add
	if (add > 0)
		simulation(cnt + 1, result + numbers[cnt], add - 1, sub, mul, div);

	//sub
	if (sub > 0)
		simulation(cnt + 1, result - numbers[cnt], add, sub - 1, mul, div);

	//mul
	if (mul > 0)
		simulation(cnt + 1, result * numbers[cnt], add, sub, mul - 1, div);

	//div
	if (div > 0)
		simulation(cnt + 1, result / numbers[cnt], add, sub, mul, div - 1);
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0); 

	memset(oper, 0, sizeof(int));
	result_min = 999999999;
	result_max = -999999999;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> numbers[i];
		
	for (int i = 0; i < 4; i++)
		cin >> oper[i]; // add, sub, mul, div

	simulation(1, numbers[0], oper[0], oper[1], oper[2], oper[3]);

	cout << result_max << "\n" << result_min << "\n";
		 
	return 0;
}
