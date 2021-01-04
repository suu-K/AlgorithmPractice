/*
문제 : 파도반 수열(https://www.acmicpc.net/problem/9461)
 */

#include <iostream>

using namespace std;

long long cache[101] = { 0,1,1,1,2,2,3,4,5,7,9 };


int main() {
	int c = 0, n = 0;
	for (int i = 11; i <= 100; i++)
		cache[i] = cache[i - 1] + cache[i - 5];
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		cout << cache[n] << endl;
	}
	return 0;
}
