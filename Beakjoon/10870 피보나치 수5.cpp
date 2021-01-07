/*
문제 : 피보나치 수 5(https://www.acmicpc.net/problem/10870)
 */
#include <iostream>

using namespace std;

int pibo(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return pibo(n - 1) + pibo(n - 2);
}

int main() {
	int n;
	cin >> n;
	cout << pibo(n) << endl;
	return 0;
}
