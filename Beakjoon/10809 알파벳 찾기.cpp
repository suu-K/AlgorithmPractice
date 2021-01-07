/*
문제 : 알파벳 찾기 (https://www.acmicpc.net/problem/10809)
*/

#include <iostream>

using namespace std;

int main() {
	int a[26];
	string word;
	cin >> word;
	for (int i = 0; i < 26; i++) {
		a[i] = -1;
	}
	for (int i = 0; i < word.size(); i++) {
		if (a[word[i] - 'a'] == -1) {
			a[word[i] - 'a'] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}