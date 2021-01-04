/*
πÆ¡¶ : ≈Õ∑ø(https://www.acmicpc.net/problem/1002)
 */
#include <iostream>
#include <cmath>

using namespace std;


int main() {
	int c;
	int x1, y1, r1;
	int x2, y2, r2;
	double d;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		if (d > (r1 + r2))
			cout << 0 << endl;
		else if (d < (r1 + r2) && d > abs(r1 - r2))
			cout << 2 << endl;
		else if (d < abs(r1 - r2))
			cout << 0 << endl;
		else if (d == 0 && r1 - r2 == 0)
			cout << -1 << endl;
		else if (d == (r1 + r2) || d == abs(r1 - r2))
			cout << 1 << endl;
	}
	return 0;
}
