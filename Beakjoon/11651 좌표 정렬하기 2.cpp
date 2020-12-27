/*
���� : ��ǥ �����ϱ�2(https://www.acmicpc.net/problem/11651)
 2���� ��� ���� �� N���� �־�����. ��ǥ�� y��ǥ�� �����ϴ� ������, yǥ�� ������ x��ǥ�� �����ϴ� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 ù° �ٿ� ���� ���� N (1 �� N �� 100,000)�� �־�����.
 ��° �ٺ��� N���� �ٿ��� i������ ��ġ xi�� yi�� �־�����. (-100,000 �� xi, yi �� 100,000)
 ��ǥ�� �׻� �����̰�, ��ġ�� ���� �� ���� ����.

���
 ù° �ٺ��� N���� �ٿ� ���� ������ ����� ����Ѵ�.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	int x;
	int y;
	point(int a, int b) : x(a), y(b) {};
}typedef point;

bool inc(point a, point b) {
	if (a.y < b.y)
		return true;
	else if (a.y == b.y)
		if (a.x < b.x)
			return true;
	return false;
}

int main() {
	int n;
	int a, b;
	vector<point> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(point(a, b));
	}
	sort(v.begin(), v.end(), inc);
	for (int i = 0; i < v.size(); i++) {
		printf("%d %d\n", v[i].x, v[i].y);
	}
	return 0;
}
