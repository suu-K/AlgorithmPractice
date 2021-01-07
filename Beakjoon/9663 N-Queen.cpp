/*
문제 : N-Queen(https://www.acmicpc.net/problem/9663)

풀이
	해당 열의 몇 번쨰 칸에 퀸이 이미 놓여져 있는지를 저장하고 퀸을 놓을 때마다 겹치는 구간이 있는지 검사하며 완전탐색을 한다.
 */

#include <iostream>

using namespace std;

int col[15];
int cnt = 0, n = 0;

bool check(int y, int x) {		//다른 퀸이 같은 열 혹은 같은 행 혹은 대각선상에 위치하였는지 검사
	for (int i = 0; i < x; i++) {
		if (col[i] == y || i - x == col[i] - y || i - x == y - col[i])
			return false;
	}
	return true;
}

void nq(int x) {
	if (x == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check(i, x)) {
			col[x] = i;
			nq(x + 1);
			col[x] = -1;
		}
	}
}

int main() {
	cin >> n;
	nq(0);
	cout << cnt << endl;
	return 0;
}