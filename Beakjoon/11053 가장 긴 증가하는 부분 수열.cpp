/*
문제 : 가장 긴 증가하는 부분 수열(https://www.acmicpc.net/problem/11053)
 */

#include <iostream>

using namespace std;

int a[1001];
int cache[1001];
int n;

int lis(int idx) {
	if (idx > n)
		return 0;

	int& ret = cache[idx];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int next = idx + 1; next <= n; next++) {
		if (a[next] > a[idx])
			ret = max(ret, lis(next) + 1);
	}

	return ret;
}

void reset() {
	for (int i = 0; i < 1001; i++)
		cache[i] = -1;
}

int main() {
	cin >> n;
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	reset();

	cout << lis(0) << endl;

	return 0;
}