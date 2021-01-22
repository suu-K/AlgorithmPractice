/*
문제 : 큐 2(https://www.acmicpc.net/problem/18258)
 */

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	queue<int> que;
	string s;
	int n;
	cin >> n;
	cin.ignore(1, '\n');
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		if (s == "pop") {
			if (que.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << que.front() << '\n';
			que.pop();
		}
		else if (s == "size")
			cout << que.size() << '\n';
		else if (s == "empty")
			if (que.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		else if (s == "front") {
			if (que.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << que.front() << '\n';
		}
		else if (s == "back") {
			if (que.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << que.back() << '\n';
		}
		else if (s.substr(0, 4) == "push") {
			int t = stoi(s.substr(5, s.size() - 5));
			que.push(t);
		}
	}


	return 0;
}