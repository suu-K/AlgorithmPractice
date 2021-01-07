/*
문제 : 네 번쨰 점(https://www.acmicpc.net/problem/3009)
 */

#include <iostream>

using namespace std;

struct point {
	int x;
	int y;
}typedef point;

int main() {
	point a, b, c, d;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	if (a.x == b.x)
		d.x = c.x;
	else if (a.x == c.x)
		d.x = b.x;
	else
		d.x = a.x;
	if (a.y == b.y)
		d.y = c.y;
	else if (a.y == c.y)
		d.y = b.y;
	else
		d.y = a.y;
	cout << d.x << " " << d.y << endl;
	return 0;
}
