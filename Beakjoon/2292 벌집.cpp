/*
¹®Á¦ : ¹úÁý(https://www.acmicpc.net/problem/2292)
 */

#include <iostream>

using namespace std;

int main() {
	int n = 0;
	int sum = 1;
	cin >> n;
	for (int i = 0;; i++) {
		sum += 6 * i;
		if (sum >= n) {
			cout << i + 1 << endl;
			break;
		}
	}
	return 0;
}