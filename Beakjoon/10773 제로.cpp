/*
문제 : 제로(https://www.acmicpc.net/problem/10773)
 */

#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> stk;
	int k;
	int tmp;
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> tmp;
		if (tmp == 0)
			stk.pop();
		else
			stk.push(tmp);
	}

	int sum = 0;
	while (!stk.empty()) {
		sum += stk.top();
		stk.pop();
	}

	cout << sum << endl;
	return 0;
}