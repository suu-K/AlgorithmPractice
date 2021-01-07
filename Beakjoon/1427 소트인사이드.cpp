/*
문제 : 소트인사이드(https://www.acmicpc.net/problem/1427)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n = 0;
	int ret = 0;
	vector<int> v;
	cin >> n;
	while (n > 0) {
		v.push_back(n % 10);
		n /= 10;
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size(); i++) {
		ret = ret * 10 + v[i];
	}
	cout << ret << endl;
	return 0;
}
