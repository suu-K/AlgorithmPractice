/*
문제 : 덱(https://www.acmicpc.net/problem/10866)
 */

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> dq;
	string s;
	int n;
	cin >> n;
	cin.ignore(1, '\n');
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		if (s == "pop_front") {
			if (dq.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << dq.front() << endl;
			dq.pop_front();
		}
		else if (s == "pop_back") {
			if (dq.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << dq.back() << endl;
			dq.pop_back();
		}
		else if (s == "size")
			cout << dq.size() << endl;
		else if (s == "empty")
			if (dq.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		else if (s == "front") {
			if (dq.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << dq.front() << endl;
		}
		else if (s == "back") {
			if (dq.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << dq.back() << endl;
		}
		else if (s.substr(0, 10) == "push_front") {
			int t = stoi(s.substr(11, s.size() - 11));
			dq.push_front(t);
		}
		else if (s.substr(0, 9) == "push_back") {
			int t = stoi(s.substr(10, s.size() - 10));
			dq.push_back(t);
		}
	}
	return 0;
}