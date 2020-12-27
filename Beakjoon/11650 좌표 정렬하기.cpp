/*
���� : ��ǥ �����ϱ�(https://www.acmicpc.net/problem/11650)
 2���� ��� ���� �� N���� �־�����. ��ǥ�� x��ǥ�� �����ϴ� ������, x��ǥ�� ������ y��ǥ�� �����ϴ� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

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
	if (a.x < b.x)
		return true;
	else if (a.x == b.x)
		if (a.y < b.y)
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
