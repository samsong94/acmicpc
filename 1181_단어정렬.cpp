/*
	vector<string>���� �Է¹ް� ���� ������ �ܾ���̿� ������ ����
	unique�� ����Ͽ� �ߺ��� ���ְ� erase�� ����� ���ʿ��� ���� ����
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
	if (a.length() == b.length())  // ���̰� ������
		return a < b;
	else  // �� �ܿ��� ���� �� ����
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
