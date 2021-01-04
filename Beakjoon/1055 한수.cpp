/*
문제 : 한수 (https://www.acmicpc.net/problem/1065)
*/

#include <iostream>
#include <vector>

using namespace std;

bool func(int n) {
	vector<int> v;
	int num = n, d = 0, nd = 0;
	while (num != 0) {
		v.push_back(num % 10);
		num /= 10;
	}
	if (v.size() < 3)
		return true;
	d = v[1] - v[0];
	for (int i = 0; i < v.size() - 1; i++) {
		if (d != (nd = v[i + 1] - v[i]))
			return false;
		d = nd;
	}
	return true;
}

int main() {
	int n = 0;
	int num = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (func(i))
			num++;
	}
	cout << num << endl;
	return 0;
}
