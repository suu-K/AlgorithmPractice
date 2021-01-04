/*
문제 : 분수찾기(https://www.acmicpc.net/problem/1193)
 */

#include <iostream>

using namespace std;

int main() {
	int n = 0, sum = 0;;
	int x, y;
	cin >> n;
	for (x = 0; n > sum; sum += ++x) {}
	if (x % 2 == 0)
		cout << x - (sum - n) << "/" << 1 + (sum - n) << endl;
	else
		cout << 1 + (sum - n) << "/" << x - (sum - n) << endl;
	return 0;
}