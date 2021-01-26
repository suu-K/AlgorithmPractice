/*
문제 : 회전하는 큐(https://www.acmicpc.net/problem/1021)
 */

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();
	deque<int> dq;
	vector<int> v;
	int left = 0, right = 0, sum = 0;
	int n, m, tmp;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		dq.push_back(i);
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		while (v[i] != dq.front()) {	//왼쪽으로 회전
			dq.push_back(dq.front());
			dq.pop_front();
			left++;
		}
		right = dq.size() - left;
		if (left <= right)
			sum += left;
		else
			sum += right;
		dq.pop_front();
		left = 0; right = 0;
	}
	cout << sum << endl;

	return 0;
}