/*
문제 : 단어 공부 (https://www.acmicpc.net/problem/1157)
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	string word;
	int max = 0;
	char answer;
	bool check = true;
	int a[26] = { 0 };
	cin >> word;
	for (int i = 0; i < word.size(); i++) {
		word[i] = toupper(word[i]);
		a[word[i] - 'A']++;
		if (max < a[word[i] - 'A']) {
			max = a[word[i] - 'A'];
			answer = word[i];
			check = true;
		}
		else if (max == a[word[i] - 'A']) {
			check = false;
		}
	}
	if (check)
		cout << answer << endl;
	else
		cout << "?" << endl;

	return 0;
}