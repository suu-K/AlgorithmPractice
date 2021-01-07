/*
문제 : 계단 오르기(https://www.acmicpc.net/problem/2579)
 */

#include <iostream>

using namespace std;

int arr[300];
int cache[300];

int main() {
	int n;
	int tmp;

	for (int i = 0; i < 300; i++) {
		arr[i] = 0;
		cache[i] = 0;
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr[i] = tmp;
	}


	cache[0] = arr[0];
	cache[1] = arr[0] + arr[1];
	cache[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for (int i = 3; i < n; i++)
		cache[i] = max((cache[i - 2] + arr[i]), (cache[i - 3] + arr[i - 1] + arr[i]));

	cout << cache[n - 1] << endl;

	return 0;
}