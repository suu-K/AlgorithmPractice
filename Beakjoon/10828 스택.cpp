/*
문제 : 스택(https://www.acmicpc.net/problem/10828)
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack<int> stk;
	string s;
	int n;
	cin >> n;
	cin.ignore(1, '\n');
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		if (s == "pop") {
			if (stk.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << stk.top() << endl;
			stk.pop();
		}
		else if (s == "size")
			cout << stk.size() << endl;
		else if (s == "empty")
			if (stk.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		else if (s == "top") {
			if (stk.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << stk.top() << endl;
		}
		else if (s.substr(0, 4) == "push") {
			int t = stoi(s.substr(5, s.size() - 5));
			stk.push(t);
		}
	}


	return 0;
}