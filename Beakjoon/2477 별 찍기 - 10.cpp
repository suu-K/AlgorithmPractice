/*
¹®Á¦ : º° Âï±â - 10(https://www.acmicpc.net/problem/2477)
 */
#include <iostream>

using namespace std;

bool a[2200][2200] = { '\0' };

void star(int y, int x, int n) {
	if (n == 3) {
		a[y][x] = true;
		a[y][x + 1] = true;
		a[y][x + 2] = true;
		a[y + 1][x] = true;
		a[y + 1][x + 2] = true;
		a[y + 2][x] = true;
		a[y + 2][x + 1] = true;
		a[y + 2][x + 2] = true;
		return;
	}
	int k = n / 3;
	star(y, x, n / 3);
	star(y, x + k, n / 3);
	star(y, x + k + k, n / 3);
	star(y + k, x, n / 3);
	star(y + k, x + k + k, n / 3);
	star(y + k + k, x, n / 3);
	star(y + k + k, x + k, n / 3);
	star(y + k + k, x + k + k, n / 3);
	return;
}

void printStar(int n) {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (a[y][x])
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return;
}

int main() {
	int n = 0;
	cin >> n;
	star(0, 0, n);
	printStar(n);
	return 0;
}