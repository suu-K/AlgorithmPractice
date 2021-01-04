/*
문제 : 정수 삼각형(https://www.acmicpc.net/problem/1932)
 */

#include <iostream>

using namespace std;

int arr[500][500];
int cache[500][500];
int n;

int maxsum(int y, int x) {
	if (y == n - 1)
		return arr[y][x];

	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	ret = arr[y][x];
	ret += max(maxsum(y + 1, x), maxsum(y + 1, x + 1));
	return ret;
}

int main() {
	int tmp;
	cin >> n;

	for (int i = 0; i < 500; i++)
		for (int j = 0; j < 500; j++)
			cache[i][j] = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}

	cout << maxsum(0, 0) << endl;
	return 0;
}