/*
문제 : 소인수분해(https://www.acmicpc.net/problem/11653)
 */

#include <iostream>

using namespace std;

int main() {
	int n = 0;
	int i = 2;
	cin >> n;
	while (n != 1) {
		if (n % i == 0) {
			cout << i << endl;
			n /= i;
		}
		else
			i++;
	}
	return 0;
}
