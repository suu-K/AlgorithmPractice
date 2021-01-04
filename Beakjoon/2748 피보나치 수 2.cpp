/*
���� : �Ǻ���ġ �� 2(https://www.acmicpc.net/problem/2748)

Ǯ��
	�־�����n�� Ŀ���� 4����Ʈ�� int�����δ� ��� ��Ƴ� �� �����Ƿ� long long�� �̿��ߴ�.
 */

#include <iostream>

using namespace std;

long long cache[90];

long long fibo(int n) {
	if (n == 0)
		return cache[n] = 0;
	if (n == 1)
		return cache[n] = 1;
	long long& ret = cache[n];
	if (ret != 0)
		return ret;
	return ret = fibo(n - 2) + fibo(n - 1);
}

int main() {
	int n = 0;
	cin >> n;
	cout << fibo(n) << endl;
	return 0;
}
