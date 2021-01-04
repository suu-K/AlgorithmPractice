/*
문제 : 피보나치 수 2(https://www.acmicpc.net/problem/2748)

풀이
	주어지는n이 커지면 4바이트의 int형으로는 모두 담아낼 수 없으므로 long long을 이용했다.
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
