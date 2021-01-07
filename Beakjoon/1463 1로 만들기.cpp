/*
문제 : 1로 만들기(https://www.acmicpc.net/problem/1463)
 */

#include <iostream>
#define MAXNUM 9999999
using namespace std;

int cache[1000001];

int makeOne(int x) {
	if (x == 1)
		return 0;
	else if (x < 1)
		return MAXNUM;

	int& ret = cache[x];
	if (ret != -1)
		return ret;

	ret = x;
	if (x % 3 == 0)
		ret = min(ret, makeOne(x / 3) + 1);
	if (x % 2 == 0)
		ret = min(ret, makeOne(x / 2) + 1);
	ret = min(ret, makeOne(x - 1) + 1);
	return ret;
}

int main() {
	int n = 0;
	cin >> n;

	for (int i = 0; i < 1000001; i++) {
		cache[i] = -1;
	}

	cout << makeOne(n);
}