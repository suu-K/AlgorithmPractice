/*
문제 : RGB거리(https://www.acmicpc.net/problem/1149)
 RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
 집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

 1번 집의 색은 2번 집의 색과 같지 않아야 한다.
 N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
 i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

입력
 첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다.
 둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다.
 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

출력
 첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.
 */

#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

vector<vector<int>> v;
vector<vector<int>> cache(1000, vector<int>(3, -1));
int n = 0;

int price(int idx, int color) {	//0이면 red, 1면 green, 2이면 blue
	if (idx == n)
		return 0;

	int& ret = cache[idx][color];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int i = 0; i < 3; i++) {
		if (i != color)
			ret = min(ret, v[idx][color] + price(idx + 1, i));
	}
	return ret;
}

int main() {
	int r, g, b;
	cin >> n;
	int m = INF;
	vector<int> rgb;
	for (int i = 0; i < n; i++) {
		cin >> r >> g >> b;
		rgb.push_back(r);
		rgb.push_back(g);
		rgb.push_back(b);
		v.push_back(rgb);
		rgb.clear();
	}
	for (int i = 0; i < 3; i++)
		m = min(m, price(0, i));
	cout << m << endl;
	return 0;
}
