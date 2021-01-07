/*
문제 : OX퀴즈 (https://www.acmicpc.net/problem/8958)
*/

#include <iostream>
#include <vector>

using namespace std;

int score(string ox) {
	int score = 0;
	int num = 1;
	for (int i = 0; i < ox.size(); i++) {
		if (ox[i] == 'O') {
			score += num;
			num += 1;
		}
		else if (ox[i] == 'X') {
			num = 1;
		}
	}
	return score;
}

int main() {
	int c = 0;
	string ox;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> ox;
		cout << score(ox) << endl;
	}

	return 0;
}