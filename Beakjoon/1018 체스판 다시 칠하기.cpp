/*
문제 : 체스판 다시 칠하기(https://www.acmicpc.net/problem/1018)
 */

#include <iostream>

using namespace std;

int board[50][50];

int check(int y, int x) {
	int start = board[y][x];
	int before = !start;
	int count1 = 0, count2 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (before == board[y + i][x + j])
				count1++;
			before = !before;
		}
		before = !before;
	}
	before = start;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (before == board[y + i][x + j])
				count2++;
			before = !before;
		}
		before = !before;
	}
	return min(count1, count2);
}

int main() {
	int n = 0, m = 0;
	string s;
	int count = 65;
	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		cin >> s;
		for (int x = 0; x < m; x++) {
			if (s[x] == 'W')
				board[y][x] = 1;
			else
				board[y][x] = 0;
		}
	}
	for (int y = 0; y <= n - 8; y++) {
		for (int x = 0; x <= m - 8; x++) {
			count = min(count, check(y, x));
		}
	}
	cout << count << endl;
	return 0;
}
