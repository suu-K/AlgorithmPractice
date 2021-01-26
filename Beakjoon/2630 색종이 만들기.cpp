/*
문제 : 색종이 만들기(https://www.acmicpc.net/problem/2630)
 */

#include <iostream>
#include <vector>

using namespace std;

int arr[128][128];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int check(int y, int x, int n) {	//-1이면 false, 0이면 흰색, 1이면 파랑
	int color = arr[y][x];
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr[i][j] != color)
				return -1;
		}
	}
	return color;
}

pair<int, int> slice(int y, int x, int n) {	//x,y에서 n사이 흰색 개수
	if (n == 0)
		return pair<int, int>(0, 0);

	switch (check(y, x, n)) {
	case 1:
		return pair<int, int>(0, 1);
	case 0:
		return pair<int, int>(1, 0);
	default:;
	}

	int white = 0, blue = 0, half = n / 2;
	pair<int, int> p;

	p = slice(y, x, half);
	white += p.first;
	blue += p.second;
	p = slice(y + half, x, half);
	white += p.first;
	blue += p.second;
	p = slice(y, x + half, half);
	white += p.first;
	blue += p.second;
	p = slice(y + half, x + half, half);
	white += p.first;
	blue += p.second;

	return pair<int, int>(white, blue);
}


int main() {
	init();
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	pair<int, int> p = slice(0, 0, n);
	cout << p.first << endl;
	cout << p.second << endl;
	return 0;
}