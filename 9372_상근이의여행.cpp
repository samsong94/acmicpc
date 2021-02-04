/*
    찾아보니까 간선의 가중치가 1과 같고 모든 노드는 연결되어있어야하므로 결과는 N-1이라고한다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;


int T, N, M, a, b;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {

		//입력
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
		}
		cout << N-1 << "\n";
	}

	return 0; 
}
