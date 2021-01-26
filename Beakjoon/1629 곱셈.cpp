/*
¹®Á¦ : °ö¼À(https://www.acmicpc.net/problem/1629)
 */

#include <iostream>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

long long power(long long a, long long b, long long c) {
	if (b == 1)
		return a % c;
	else if (b == 0)
		return 1;

	long long k = power(a, b / 2, c) % c;

	if (b % 2 == 0) {
		return (k * k) % c;
	}
	else
		return (((k * k) % c) * a) % c;
}


int main() {
	init();
	long long a, b, c;
	cin >> a >> b >> c;

	cout << power(a, b, c) << endl;

	return 0;
}