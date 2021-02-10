/*
	stable_sort를 쓰거나 아니면 아래와 같이쓰기
	
	* stable_sort일때 비교 함수
	bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, age;
string name;
vector<pair<int, pair<int, string>>> list;

bool cmp(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b) {
	if (a.second.first == b.second.first) {
		return a.first < b.first;
	}
	else
		return a.second.first < b.second.first;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		list.push_back(make_pair(i, make_pair(age, name)));
	}

	sort(list.begin(), list.end(), cmp);

	for (int i = 0; i < N; i++)
		cout << list[i].second.first << " " << list[i].second.second << "\n";

	return 0;
}
