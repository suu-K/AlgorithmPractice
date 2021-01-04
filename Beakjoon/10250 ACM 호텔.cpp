/*
문제 : ACM 호텔(https://www.acmicpc.net/problem/10250)
 */

#include <iostream>

using namespace std;

int func(int h, int w, int n) {
	int y, x;
	if (n % h != 0) {
		y = n % h;
		x = n / h + 1;
	}
	else {
		y = h;
		x = n / h;
	}
	return y * 100 + x;
}

int main() {
	int t;
	int h, w, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> h >> w >> n;
		cout << func(h, w, n) << endl;
	}
	return 0;
}