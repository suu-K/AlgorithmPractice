/*
문제 : N-Queen(https://www.acmicpc.net/problem/9663)
 N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
 N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
 첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
 첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
 */

#include <iostream>

using namespace std;

int col[15];
int cnt = 0, n = 0;

bool check(int y, int x) {
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