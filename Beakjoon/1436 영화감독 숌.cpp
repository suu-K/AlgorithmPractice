/*
문제 : 영화감독 숌(https://www.acmicpc.net/problem/1436)
 */

#include <iostream>

using namespace std;

bool check(int n) {
	int cnt = 0;
	while (n > 0) {
		if (n % 10 != 6)
			cnt = 0;
		else
			cnt++;
		if (cnt == 3)
			return true;
		n /= 10;
	}
	return false;
}

int find(int n) {
	int cnt = 0;
	int ret = 0;
	for (int i = 666; cnt < n; i++) {
		if (check(i)) {
			cnt++;
			ret = i;
		}
	}
	return ret;
}


int main() {
	int n = 0;
	cin >> n;
	cout << find(n) << endl;
	return 0;
}
