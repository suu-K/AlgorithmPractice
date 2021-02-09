/*
문제 : AC(https://www.acmicpc.net/problem/5430)
 */

#include <iostream>
#include <deque>
#include <string>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

pair<bool, bool> func(string& s, deque<int>& dq) {
	bool forword = true;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'R')
			forword = !forword;
		else if (forword) {
			if (dq.empty()) {
				cout << "error" << endl;
				return pair<int, int>(false, forword);
			}
			dq.pop_front();
		}
		else {
			if (dq.empty()) {
				cout << "error" << endl;
				return pair<int, int>(false, forword);
			}
			dq.pop_back();
		}
	}
	return pair<int, int>(true, forword);
}

void printDq(deque<int>& dq, bool forword) {
	if (forword) {
		cout << '[';
		for (; dq.size() > 1;) {
			cout << dq.front() << ',';
			dq.pop_front();
		}
		if (!dq.empty())
			cout << dq.front();
		cout << ']' << endl;
	}
	else {
		cout << '[';
		for (; dq.size() > 1;) {
			cout << dq.back() << ',';
			dq.pop_back();
		}
		if (!dq.empty())
			cout << dq.front();
		cout << ']' << endl;
	}
}

int main() {
	init();
	int t, n;
	string s, input;
	deque<int> dq;
	cin >> t;
	for (int k = 0; k < t; k++) {
		dq.clear();
		cin >> s;
		cin >> n >> input;

		int i = 0, j = 0;
		while (i < input.size()) {
			if (input[i] == '[' || input[i] == ',' || input[i] == ']') {
				i++;
				continue;
			}
			j = 0;
			while (input[i + j] != '[' && input[i + j] != ',' && input[i + j] != ']')
				j++;
			dq.push_back(stoi(input.substr(i, j)));
			i += j;
		}

		pair<bool, bool> p = func(s, dq);
		if (p.first) {
			printDq(dq, p.second);
		}

	}

	return 0;
}