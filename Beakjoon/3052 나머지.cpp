/*
문제 : 나머지 (https://www.acmicpc.net/problem/3052)
*/

#include <iostream>

using namespace std;

int main() {
	int num[10] = { 0 };
	int arr[42] = { 0 };
	int n = 0;

	for (int i = 0; i < 10; i++) {
		cin >> num[i];
		arr[num[i] % 42]++;
	}
	for (int i = 0; i < 42; i++)
		if (arr[i] != 0)
			n++;

	cout << n << endl;

	return 0;
}