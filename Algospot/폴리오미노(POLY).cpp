/*
문제 - 폴리오미노(POLY)(https://algospot.com/judge/problem/read/POLY)

풀이
	사실 문제를 처음 읽으면 문제를 정확히 이해하기가 힘들다.
	세로 단조 폴리오미노라는 것이 뒤집거나 회전시켰을 경우 어떻게 판정이 되는지 하나도 예시가 있지 않다.
	그러나 입력처럼 2가 입력되면 2개의 정사각형이 가로로 나란히 있는 것과 세로로 나란히 있는 것을 다른 경우로 취급한 것을 알 수 있다.
	또한 4가 입력되었을 경우도 19개가 나오는 것으로 보아 회전하거나 뒤집힌 경우는 모두 다른 경우라고 할 수 있겠다.

	따라서 정사각형이 나열되는 모든 경우의 수를 출력하면 된다.
	이를 완전탐색 하는 방법은 맨 윗단에서부터 가로로 차례대로 정사각형을 나열하면 된다.
	n개가 입력되면 맨 윗단에 1개를, 그리고 그 아래에 n-1개의 폴리오미노를 놓고 둘을 이어붙이면 된다.
*/


#include <iostream>
#define MOD 10000000

using namespace std;

int cache[101][101];

int poly(int n, int x) {	//위에 x개의 조각이 있을 떄 n개의 폴리오미노를 구하는 함수
	if (n == 0)		//조각을 모두 나열했을 경우 1개를 셈
		return 1;

	int& ret = cache[n][x];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = 1; i <= n; i++) {	//맨 윗단에 i개를 놓는 경우
		if (x == 0)
			ret += poly(n - i, i);	//현재 폴리오미노 위가 비어있으므로 맷 윗단에 i개의 조각을 놓는다.
		else
			ret += (i + x - 1) * poly(n - i, i);	//맨 윗단의 x개와 그 다음 단의 i개가 이어붙을 수 있는 경우의 수는 i+x-1개
		ret %= MOD;
	}
	return ret;
}

void reset() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			cache[i][j] = -1;
		}
	}
}

int main() {
	int c;
	int n;
	cin >> c;
	reset();
	for (int i = 0; i < c; i++) {
		cin >> n;
		cout << poly(n, 0) << endl;
	}
	return 0;
}