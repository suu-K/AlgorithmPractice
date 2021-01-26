/*
문제 : 쿼드트리(https://www.acmicpc.net/problem/1992)
 */

#include <iostream>
#include <vector>

using namespace std;

int arr[64][64];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int check(int y, int x, int n) {	//-1이면 false, 0이면 흰색, 1이면 검정
	int color = arr[y][x];
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr[i][j] != color)
				return -1;
		}
	}
	return color;
}

void slice(int y, int x, int n) {	//x,y에서 n사이 흰색 개수
	if (n == 0)
		return;

	int ret;
	switch (ret = check(y, x, n)) {
	case 1:
		cout << ret;
		return;
	case 0:
		cout << ret;
		return;
	default:;
	}

	int white = 0, black = 0, half = n / 2;
	pair<int, int> p;

	cout << "(";
	slice(y, x, half);
	slice(y, x + half, half);
	slice(y + half, x, half);
	slice(y + half, x + half, half);
	cout << ")";
}


int main() {
	init();
	int n, tmp;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	slice(0, 0, n);
	cout << endl;
	return 0;
}