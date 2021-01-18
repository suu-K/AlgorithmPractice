/*
문제 : 오큰수(https://www.acmicpc.net/problem/17298)
 */


#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int n;
	int tmp;
	vector<int> v;
	stack<int> s;
	cin >> n;
	vector<int> ret(n, -1);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	s.push(0);
	for (int i = 1; i < n; i++) {
		while (!s.empty() && v[s.top()] < v[i]) {
			ret[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < n; i++) {
		cout << ret[i] << " ";
	}

	return 0;
}