/*
문제 : 행렬 곱셈(https://www.acmicpc.net/problem/2740)
 */

#include <iostream>

using namespace std;

int a[100][100];
int b[100][100];
int mul[100][100];
int n, m, k;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int sum(int y, int x) {	//행렬의 x, y 좌표의 의 값을 계산하는 함수
	int ret = 0;
	for (int i = 0; i < m; i++) {
		ret += a[y][i] * b[i][x];
	}
	return ret;
}

void ans() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			mul[i][j] = sum(i, j);
		}
	}
}

int main() {
	init();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> b[i][j];
		}
	}

	ans();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << mul[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}