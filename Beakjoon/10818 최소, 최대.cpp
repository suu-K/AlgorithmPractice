/*
문제 : 최소, 최대 (https://www.acmicpc.net/problem/10818)
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0;
	int minimum = 1000001, maximum = -1000001;
	int tmp;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		minimum = min(minimum, v[i]);
		maximum = max(maximum, v[i]);
	}
	cout << minimum << " " << maximum << endl;

	return 0;
}