/*
���� : ���簢������ Ż��(https://www.acmicpc.net/problem/1085)
 */

#include <iostream>

using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int m = 1001;
	m = min(x, y);
	m = min(m, w - x);
	m = min(m, h - y);
	cout << m << endl;
	return 0;
}
