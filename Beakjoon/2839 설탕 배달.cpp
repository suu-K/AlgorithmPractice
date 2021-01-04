/*
문제 : 설탕 배달(https://www.acmicpc.net/problem/2839)
 */

#include <iostream>
#define INF 5000
using namespace std;

int main() {
	int n = 0;
	int sum = INF;
	cin >> n;
	for (int i = 1; 5 * i <= n; i++) {
		if ((n - (i * 5)) % 3 == 0)
			sum = min(sum, i + ((n - (i * 5)) / 3));
	}
	if (n % 3 == 0)
		sum = min(sum, n / 3);
	if (sum == INF)
		cout << -1 << endl;
	else
		cout << sum << endl;
	return 0;
}