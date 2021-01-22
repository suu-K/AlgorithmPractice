/*
문제 : 카드2(https://www.acmicpc.net/problem/2164)
 */

#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	queue<int> que;
	cin >> n;
	for (int i = 1; i <= n; i++)
		que.push(i);

	while (que.size() != 1) {
		que.pop();
		if (que.size() == 1)
			break;
		que.push(que.front());
		que.pop();
	}

	cout << que.front() << endl;

	return 0;
}