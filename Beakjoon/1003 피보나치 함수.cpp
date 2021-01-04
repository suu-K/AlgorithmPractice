/*
문제 : 피보나치 함수(https://www.acmicpc.net/problem/1003)

풀이
 0이 호출되는 횟수는 n-1번째, 1이 호출된는 횟수는 n번쨰 피보나치 수와 같다.
 단 n=0일떄와 n=1일때는 예외로 한다.
 */

#include <iostream>

using namespace std;

long long cache[40];

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
	int c = 0;
	int n = 0;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		if (n == 0)
			cout << 1 << " " << 0 << endl;
		else if (n == 1)
			cout << 0 << " " << 1 << endl;
		else
			cout << fibo(n - 1) << " " << fibo(n) << endl;
	}
	return 0;
}
