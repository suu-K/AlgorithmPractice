/*
문제 : 균형잡힌 세상(https://www.acmicpc.net/problem/4949)
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;


bool check(string s) {
	stack<char> remain;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[') {
			remain.push(s[i]);
		}
		else if (s[i] == ')') {
			if (!remain.empty() && remain.top() == '(')
				remain.pop();
			else
				return false;
		}
		else if (s[i] == ']') {
			if (!remain.empty() && remain.top() == '[')
				remain.pop();
			else
				return false;
		}
	}
	if (remain.empty())
		return true;
	else
		return false;
}


int main() {
	string s;

	getline(cin, s);
	while (s.size() != 1 || s[0] != '.') {

		if (check(s))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		getline(cin, s);
	}

	return 0;
}