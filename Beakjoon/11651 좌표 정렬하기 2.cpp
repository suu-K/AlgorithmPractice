/*
문제 : 좌표 정렬하기2(https://www.acmicpc.net/problem/11651)
 2차원 평면 위의 점 N개가 주어진다. 좌표를 y좌표가 증가하는 순으로, y표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

입력
 첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다.
 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000)
 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

출력
 첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.
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
