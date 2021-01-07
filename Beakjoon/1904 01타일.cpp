/*
문제 : 01타일(https://www.acmicpc.net/problem/1904)

풀이
	처음부터 차례대로 1 혹은 00을 이어붙여 나간다.
	11은 1을 두번 이어붙이는 경우이므로 세지 않는다.
	또한 계산 결과가 일반적인 자료형이 받아들일 수 있는 수보다 크므로 반환값을 항상 15746으로 나눈 나머지로 한다.
 */

#include <iostream>
#define MOD 15746

using namespace std;

int cache[1000001];

int count(int n) {
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	int& ret = cache[n];
	if (ret != -1)
		return ret;

	return ret = (count(n - 1) + count(n - 2)) % MOD;
}

int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < 1000001; i++)
		cache[i] = -1;
	cout << count(n) << endl;
	return 0;
}
