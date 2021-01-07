/*
문제 : 블랙잭(https://www.acmicpc.net/problem/2798)
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0, m = 0, tmp = 0;
	int sum = 0;	//세 수의 합
	int close = -1;	//가장 가까운 값
	vector<int> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = v[i] + v[j] + v[k];
				if (m - sum == 0) {
					cout << sum << endl;
					return 0;
				}
				else if (m - sum > 0 && m - close > m - sum) {
					close = sum;
				}
			}
		}
	}
	cout << close << endl;
	return 0;
}