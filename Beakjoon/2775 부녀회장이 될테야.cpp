/*
문제 : 부녀회장이 될테야(https://www.acmicpc.net/problem/2775)
 */

#include <iostream>
#include <vector>

using namespace std;

int func(int k, int n) {
	vector<int> arr(n, 1);
	for (int i = 0; i < k + 1; i++) {
		for (int j = 1; j < arr.size(); j++) {
			arr[j] += arr[j - 1];
		}
	}
	return arr[n - 1];
}

int main() {
	int t;
	int k, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k >> n;
		cout << func(k, n) << endl;
	}
	return 0;
}
