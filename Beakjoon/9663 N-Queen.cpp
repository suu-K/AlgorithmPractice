/*
���� : N-Queen(https://www.acmicpc.net/problem/9663)
 N-Queen ������ ũ�Ⱑ N �� N�� ü���� ���� �� N���� ���� ������ �� ���� ���� �����̴�.
 N�� �־����� ��, ���� ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 ù° �ٿ� N�� �־�����. (1 �� N < 15)

���
 ù° �ٿ� �� N���� ���� ������ �� ���� ���� ����� ���� ����Ѵ�.
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