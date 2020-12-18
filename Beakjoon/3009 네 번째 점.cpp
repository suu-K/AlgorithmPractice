/*
문제 : 네 번쨰 점(https://www.acmicpc.net/problem/3009)
 세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한 네 번째 점을 찾는 프로그램을 작성하시오.

입력
 세 점의 좌표가 한 줄에 하나씩 주어진다. 좌표는 1보다 크거나 같고, 1000보다 작거나 같은 정수이다.

출력
 직사각형의 네 번째 점의 좌표를 출력한다.
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
