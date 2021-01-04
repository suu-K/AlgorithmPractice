/*
문제 : 셀프 넘버 (https://www.acmicpc.net/problem/4673)
*/

#include <iostream>
#include <vector>

using namespace std;

int d(int n) {
	int num = n;
	while (n != 0) {
		num += n % 10;
		n = n / 10;
	}
	return num;
}


int main() {
	int n = 0;
	vector<bool> isSelf(10000, true);
	for (int i = 0; i < 10000; i++) {
		n = i + 1;
		if (!isSelf[i])
			continue;
		while ((n = d(n)) <= 10000) {
			isSelf[n - 1] = false;
		}
	}

	for (int i = 0; i < 10000; i++) {
		if (isSelf[i])
			cout << i + 1 << endl;
	}

	return 0;
}
