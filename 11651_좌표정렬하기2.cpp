/*
	
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, x, y;
vector<pair<int, int>> coord;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	coord.clear();

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		coord.push_back(make_pair(x, y));
	}
		
	sort(coord.begin(), coord.end(), cmp);

	for (int i = 0; i < coord.size(); i++) {
		cout << coord[i].first << " " << coord[i].second << "\n";
	}

	return 0;
}
