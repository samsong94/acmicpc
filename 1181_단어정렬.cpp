/*
	vector<string>으로 입력받고 정렬 기준은 단어길이와 사전순 정렬
	unique를 사용하여 중복을 없애고 erase를 사용해 불필요한 원소 삭제
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
string word;
vector<string> words;

bool cmp(string a, string b) {
	if (a.length() == b.length())  // 길이가 같으면
		return a < b;
	else  // 그 외에는 길이 순 정렬
		return a.length() < b.length();
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	words.clear();

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word;
		words.push_back(word);
	}

	sort(words.begin(), words.end(), cmp);
	words.erase(unique(words.begin(), words.end()), words.end());
	
	for (int i = 0; i < words.size(); i++)
		cout << words[i] << "\n";

	return 0;
}
