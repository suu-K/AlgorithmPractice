/*
문제 : 동전 0(https://www.acmicpc.net/problem/11047)
 */

#include <iostream>
#include <vector>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();
	int n, k, tmp;
	int sum = 0, cnt = 0;
	vector<int> v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = v.size() - 1; i >= 0 && sum != k; i--) {
		while (sum + v[i] <= k) {
			sum += v[i];
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}