/*
문제 : 쉬운 계단 수(https://www.acmicpc.net/problem/10844)
 */

#include <iostream>
#define MOD 1000000000

using namespace std;

int cache[101][10];
int n = 0;

int stair(int idx, int x) {
	if (idx == n)
		return 1;

	int& ret = cache[idx][x];
	if (ret != -1)
		return ret;

	ret = 0;
	if (x == 0)
		ret += stair(idx + 1, x + 1);
	else if (x == 9)
		ret += stair(idx + 1, x - 1);
	else
		ret += (stair(idx + 1, x - 1) + stair(idx + 1, x + 1)) % MOD;

	return ret %= MOD;
}


int main() {
	int sum = 0;
	cin >> n;

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 10; j++)
			cache[i][j] = -1;

	for (int i = 1; i < 10; i++) {
		sum += stair(1, i);
		sum %= MOD;
	}

	cout << sum << endl;

}