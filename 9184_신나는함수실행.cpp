/*
	dp를 사용해 재귀함수의 중복되는 부분을 저장해두고 계산되어 있다면 값을 불러와 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long int dp[21][21][21];

int w(int x, int y, int z) {
	if (x <= 0 || y <= 0 || z <= 0) 
		return 1;
	else if (x > 20 || y > 20 || z > 20)
		return w(20, 20, 20);
	else if (dp[x][y][z])
			return dp[x][y][z];
	else if (x < y && y < z)
		dp[x][y][z] = w(x, y, z - 1) + w(x, y - 1, z - 1) - w(x, y - 1, z);
	else
		dp[x][y][z] = w(x - 1, y, z) + w(x - 1, y - 1, z) + w(x - 1, y, z - 1) - w(x - 1, y - 1, z - 1);
	return dp[x][y][z];
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int a, b, c;

	while (1) {
		cin >> a >> b >> c;
		if ((a == -1 && b == -1 && c == -1))
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a,b,c) << "\n";
	}
	
	return 0;
}
