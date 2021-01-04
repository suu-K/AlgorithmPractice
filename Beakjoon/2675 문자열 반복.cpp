/*
문제 : 문자열 반복 (https://www.acmicpc.net/problem/2675)
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	int n;
	string word;
	string tmp;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> word;
		for (int j = 0; j < word.size(); j++) {
			for (int k = 0; k < n; k++) {
				tmp.push_back(word[j]);
			}
		}
		cout << tmp << endl;
		word.clear();
		tmp.clear();
	}

	return 0;
}