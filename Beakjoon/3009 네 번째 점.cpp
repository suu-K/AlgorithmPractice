/*
���� : �� ���� ��(https://www.acmicpc.net/problem/3009)
 �� ���� �־����� ��, �࿡ ������ ���簢���� ����� ���ؼ� �ʿ��� �� ��° ���� ã�� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 �� ���� ��ǥ�� �� �ٿ� �ϳ��� �־�����. ��ǥ�� 1���� ũ�ų� ����, 1000���� �۰ų� ���� �����̴�.

���
 ���簢���� �� ��° ���� ��ǥ�� ����Ѵ�.
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
