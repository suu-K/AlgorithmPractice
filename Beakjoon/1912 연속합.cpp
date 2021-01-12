/*
문제 : 연속합(https://www.acmicpc.net/problem/1912)
 */

#include <iostream>

using namespace std;


int main() {
	int num[100000] = { '\0' };
	int cache[100000];
	int cnt = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &num[i]);
		cnt++;
	}

	int ret = num[0];
	cache[0] = num[0];
	for (int i = 1; i < cnt; i++) {
		cache[i] = max(num[i], cache[i - 1] + num[i]);
		ret = max(ret, cache[i]);
	}

	cout << ret << endl;

	return 0;
}