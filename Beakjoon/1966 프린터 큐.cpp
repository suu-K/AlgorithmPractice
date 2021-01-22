/*
문제 : 프린터 큐(https://www.acmicpc.net/problem/1966)
 */

#include <iostream>
#include <list>

using namespace std;

bool check(list<int>& ls) {
	int n = ls.front();
	bool ret = true;
	list<int>::iterator it = ls.begin();
	it++;
	while (it != ls.end()) {
		if (*it > n)
			return false;
		it++;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list<int> ls;
	int c, n, m, tmp;
	int cnt;
	cin >> c;
	for (int i = 0; i < c; i++) {
		ls.clear();
		cnt = 0;
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			ls.push_back(tmp);
		}

		for (int j = 0;; j++) {
			if (check(ls)) {
				ls.pop_front();
				cnt++;
				if (m == 0)
					break;
				m--;
			}
			else {
				tmp = ls.front();
				ls.pop_front();
				ls.push_back(tmp);
				m--;
				if (m == -1)
					m = ls.size() - 1;
			}
		}

		cout << cnt << endl;
	}

	return 0;
}