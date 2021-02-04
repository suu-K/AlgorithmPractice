/*
문제 : 배수와 약수(https://www.acmicpc.net/problem/5086)
 */

#include <iostream>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();
	int a, b;
	cin >> a >> b;
	while (a != 0 || b != 0) {
		if (a > b && a % b == 0) {
			cout << "multiple" << endl;
		}
		else if (a < b && b % a == 0) {
			cout << "factor" << endl;
		}
		else
			cout << "neither" << endl;
		cin >> a >> b;
	}
	return 0;
}