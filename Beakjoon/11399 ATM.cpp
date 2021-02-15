/*
문제 : ATM(https://www.acmicpc.net/problem/11399)
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

int main() {
	init();
	int n, sum = 0;
	cin >> n;
	vector<int> v(n, 0);
	vector<int> time(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), less<int>());

	time[0] = v[0];
	for (int i = 1; i < n; i++) {
		time[i] = time[i - 1] + v[i];
	}

	for (int i = 0; i < n; i++) {
		sum += time[i];
	}

	cout << sum << endl;

	return 0;
}