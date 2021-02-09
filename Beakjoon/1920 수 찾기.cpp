/*
문제 : 수 찾기(https://www.acmicpc.net/problem/1920)

코멘트
	'\n' 대신 endl을 쓰면 시간 초과가 나온다.
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main() {
	init();
	int n, m, tmp;
	set<int> s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		s.insert(tmp);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		if (s.find(tmp) == s.end())
			cout << 0 << "\n";
		else
			cout << 1 << "\n";
	}

	return 0;
}