/*
문제 : 종이의 개수(https://www.acmicpc.net/problem/1780)
 */

#include <iostream>
#include <vector>
#define MINNUM -9999

using namespace std;

int arr[2200][2200];
int minu = 0, zero = 0, one = 0;	//-1, 0. 1 의 개수

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int check(int y, int x, int n) {	//MINNUM이면 false
	int color = arr[y][x];
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr[i][j] != color)
				return MINNUM;
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
		one++;
		return;
	case 0:
		zero++;
		return;
	case -1:
		minu++;
		return;
	default:;
	}

	int tril = n / 3;

	slice(y, x, tril);
	slice(y, x + tril, tril);
	slice(y, x + tril + tril, tril);
	slice(y + tril, x, tril);
	slice(y + tril, x + tril, tril);
	slice(y + tril, x + tril + tril, tril);
	slice(y + tril + tril, x, tril);
	slice(y + tril + tril, x + tril, tril);
	slice(y + tril + tril, x + tril + tril, tril);
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
	slice(0, 0, n);
	cout << minu << endl;
	cout << zero << endl;
	cout << one << endl;
	return 0;
}