/*
문제 : 잃어버린 괄호(https://www.acmicpc.net/problem/1541)

코멘트
	처음엔 괄호를 한쌍만 치는 줄 알았지만 사실 괄호의 개수에는 제한이 없었다.
	괄호를 무한히 칠 수 있으므로 -가 나오면 그 뒤의 숫자는 모두 -로 바꿀 수 있다.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();
	string s;
	cin >> s;
	vector<char> oper;	//부호저장
	vector<int> num;	//숫자저장

	if (s[0] != '-' || s[0] != '+')	//첫 숫자의 부호가 +라 생략됬으면
		oper.push_back('+');

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-' || s[i] == '+')	//부호일떄
			oper.push_back(s[i]);
		else {							//숫자일때
			int start = i;
			while (i != s.size() && s[i] != '-' && s[i] != '+') {
				i++;
			}
			num.push_back(stoi(s.substr(start, i - start)));
			i--;
		}
	}

	int i = 0;
	int sum = 0;
	while (oper[i] == '+')
		sum += num[i++];
	while (i < oper.size())
		sum -= num[i++];

	cout << sum << endl;

	return 0;
}