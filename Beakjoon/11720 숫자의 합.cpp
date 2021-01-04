/*
문제 : 숫자의 합 (https://www.acmicpc.net/problem/11720)
*/

#include <iostream>

using namespace std;

int main() {
	int n = 0, sum = 0;
	string str;
	cin >> n >> str;
	for (int i = 0; i < n; i++) {
		sum += (int)str[i] - '0';
	}
	cout << sum << endl;
	return 0;
}
