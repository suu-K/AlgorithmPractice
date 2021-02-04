/*
문제 : 스택 수열(https://www.acmicpc.net/problem/1874)
 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;


void p(vector<char>& v) {
	for (int i = 0; i < v.size(); i++) {
		printf("%c\n", v[i]);
	}
}

int main() {
	int n, tmp;
	stack<int> s;
	vector<char> print;

	int v[100000];
	bool ok = false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 1, j = 0; i <= n; i++) {
		s.push(i);
		print.push_back('+');

		while (!s.empty() && s.top() == v[j]) {
			s.pop();
			print.push_back('-');
			j++;
		}

		if (j == n)
			ok = true;
	}

	if (ok)
		p(print);
	else
		cout << "NO" << endl;

	return 0;
}