/*
문제 : RGB거리(https://www.acmicpc.net/problem/1149)
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
