/*
문제 : 베르트랑 공준(https://www.acmicpc.net/problem/4948)
 */

#include <iostream>
#include <cmath>

using namespace std;

void func(int a, int b) {
	int count = 0;
	int v[123456 * 2 + 1];
	for (int i = 2; i < 123456 * 2 + 1; i++)
		v[i] = true;
	v[1] = false;
	for (int i = 2; i <= sqrt(b); i++) {
		if (v[i]) {
			for (int j = i + i; j < b + 1; j += i) {
				v[j] = false;
			}
		}
	}
	for (int i = a; i < b + 1; i++)
		if (v[i])
			count++;
	printf("%d\n", count);
	return;
}

int main() {
	int n = 1;
	cin >> n;
	while (n != 0) {
		func(n + 1, 2 * n);
		cin >> n;
	}
	return 0;
}
