/*
문제 : 나머지 (https://www.acmicpc.net/problem/1546)
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0, tmp = 0;
	double nmax = 0, sum = 0;
	double avg = 0;
	vector<double> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		nmax = max(nmax, v[i]);
	}
	for (int i = 0; i < n; i++) {
		v[i] = (v[i] / nmax) * 100;
		sum += v[i];
	}
	avg = (double)sum / n;
	cout << avg << endl;

	return 0;
}