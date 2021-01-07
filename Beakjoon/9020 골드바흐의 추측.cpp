/*
문제 : 골드바흐의 추측(https://www.acmicpc.net/problem/9020)
 */

#include <iostream>
#include <cmath>

using namespace std;

void func(int n) {
	int a = 0, b = 0;
	int sub = n;
	bool v[10001];
	for (int i = 2; i < 10001; i++)
		v[i] = true;
	v[1] = false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (v[i]) {
			for (int j = i + i; j < n + 1; j += i) {
				v[j] = false;
			}
		}
	}
	for (int i = 2; i <= n / 2; i++) {
		if (v[i] && v[n - i]) {
			if (sub > n - i - i) {
				a = i;
				b = n - i;
				sub = n - i - i;
			}
		}
	}
	printf("%d %d\n", a, b);
	return;
}

int main() {
	int c = 0;
	int n = 0;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		func(n);
	}
	return 0;
}
