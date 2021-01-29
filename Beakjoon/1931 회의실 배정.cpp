/*
문제 : 회의실 배정(https://www.acmicpc.net/problem/1931)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first <= b.first;
	}
	return a.second <= b.second;
}

int main() {
	init();
	int n, a, b;	//a 시작시간, b 끝나는 시간
	int cnt = 0;
	vector<pair<int, int>> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(pair<int, int>(a, b));
	}

	sort(v.begin(), v.end(), compare);

	int cur;
	for (int i = 0; i < v.size();) {
		cur = v[i].second;
		cnt++;
		i++;
		while (i<v.size() && cur > v[i].first) {
			i++;
		}
	}

	cout << cnt << endl;

	return 0;
}