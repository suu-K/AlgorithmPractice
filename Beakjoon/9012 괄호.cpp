/*
문제 : 괄호(https://www.acmicpc.net/problem/9012)
 */

#include <iostream>
#include <stack>

using namespace std;

bool matched(string s) {
	stack<char> remain;
	for (int i = 0; i < s.size(); i++) {
		if (remain.empty()) {	//스텍이 비어있다면 무조건 삽입
			remain.push(s[i]);
			continue;
		}
		char c = remain.top();
		switch (s[i]) {
		case '(':	//여는 괄호는 무조건 삽입
			remain.push(s[i]);
			break;
		case')':							//닫는 괄호가 짝이 맞으면 제거, 아니면 실패
			if (remain.top() != '(')
				return false;
			else
				remain.pop();
			break;
		default:
			return false;
		}
	}
	if (remain.empty())
		return true;
	else
		return false;
}

int main() {
	int c;
	string s;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> s;
		if (matched(s))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}