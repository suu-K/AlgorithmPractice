/*
문제 : 그룹 단어 체커(https://www.acmicpc.net/problem/1316)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int checker(string word) {
	vector<bool> a(26, false);
	for (int i = 0; i < word.size(); i++) {
		if (a[word[i] - 'a'] == true)
			return 0;
		if (word[i] != word[i + 1])
			a[word[i] - 'a'] = true;
	}
	return 1;
}

int main() {
	int t, num = 0;
	string word;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> word;
		num += checker(word);
	}
	cout << num << endl;
	return 0;
}