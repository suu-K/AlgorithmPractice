/*
문제 : 약수(https://www.acmicpc.net/problem/1037)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	if (n % 2) {	//진짜 약수의 개수가 홀수면
		cout << v[n / 2] * v[n / 2] << endl;
	}
	else {	//짝수면
		cout << v[0] * v[n - 1] << endl;
	}
	return 0;
}