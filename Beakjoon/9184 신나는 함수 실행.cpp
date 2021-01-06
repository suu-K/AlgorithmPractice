/*
문제 : 신나는 함수 실행(https://www.acmicpc.net/problem/9184)
 */

#include <iostream>

using namespace std;

int cache[21][21][21];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);

	int& ret = cache[a][b][c];
	if (ret != -1)
		return ret;

	if (a < b && b < c)
		return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
	int a, b, c;

	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
			for (int k = 0; k < 21; k++)
				cache[i][j][k] = -1;

	cin >> a >> b >> c;
	do {
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
		cin >> a >> b >> c;
	} while (a != -1 || b != -1 || c != -1);
	return 0;
}