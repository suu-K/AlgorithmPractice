/*
���� : RGB�Ÿ�(https://www.acmicpc.net/problem/1149)
 RGB�Ÿ����� ���� N�� �ִ�. �Ÿ��� �������� ��Ÿ�� �� �ְ�, 1�� ������ N�� ���� ������� �ִ�.
 ���� ����, �ʷ�, �Ķ� �� �ϳ��� ������ ĥ�ؾ� �Ѵ�. ������ ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� �־����� ��, �Ʒ� ��Ģ�� �����ϸ鼭 ��� ���� ĥ�ϴ� ����� �ּڰ��� ���غ���.

 1�� ���� ���� 2�� ���� ���� ���� �ʾƾ� �Ѵ�.
 N�� ���� ���� N-1�� ���� ���� ���� �ʾƾ� �Ѵ�.
 i(2 �� i �� N-1)�� ���� ���� i-1��, i+1�� ���� ���� ���� �ʾƾ� �Ѵ�.

�Է�
 ù° �ٿ� ���� �� N(2 �� N �� 1,000)�� �־�����.
 ��° �ٺ��� N���� �ٿ��� �� ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� 1�� ������ �� �ٿ� �ϳ��� �־�����.
 ���� ĥ�ϴ� ����� 1,000���� �۰ų� ���� �ڿ����̴�.

���
 ù° �ٿ� ��� ���� ĥ�ϴ� ����� �ּڰ��� ����Ѵ�.
 */

#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

vector<vector<int>> v;
vector<vector<int>> cache(1000, vector<int>(3, -1));
int n = 0;

int price(int idx, int color) {	//0�̸� red, 1�� green, 2�̸� blue
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
