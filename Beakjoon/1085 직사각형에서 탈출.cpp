/*
문제 : 직사각형에서 탈출(https://www.acmicpc.net/problem/1085)
 한수는 지금 (x, y)에 있다. 직사각형의 왼쪽 아래 꼭짓점은 (0, 0)에 있고, 오른쪽 위 꼭짓점은 (w, h)에 있다.
 직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.

입력
 첫째 줄에 x, y, w, h가 주어진다.

출력
 첫째 줄에 문제의 정답을 출력한다.
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
