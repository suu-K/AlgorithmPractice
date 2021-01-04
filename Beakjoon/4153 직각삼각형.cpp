/*
문제 : 직각삼각형(https://www.acmicpc.net/problem/4153)
 */

#include <iostream>

using namespace std;

void func(int a, int b, int c) {
	bool rec = true;
	int m = max(a, b);
	m = max(m, c);
	rec = ((m * m) == (a * a + b * b + c * c - m * m));
	if (rec)
		cout << "right" << endl;
	else
		cout << "wrong" << endl;
	return;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	while (a != 0 || b != 0 || c != 0) {
		func(a, b, c);
		cin >> a >> b >> c;
	}
	return 0;
}
