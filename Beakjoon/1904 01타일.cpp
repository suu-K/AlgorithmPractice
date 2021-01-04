/*
���� : 01Ÿ��(https://www.acmicpc.net/problem/1904)

Ǯ��
	ó������ ���ʴ�� 1 Ȥ�� 00�� �̾�ٿ� ������.
	11�� 1�� �ι� �̾���̴� ����̹Ƿ� ���� �ʴ´�.
	���� ��� ����� �Ϲ����� �ڷ����� �޾Ƶ��� �� �ִ� ������ ũ�Ƿ� ��ȯ���� �׻� 15746���� ���� �������� �Ѵ�.
 */

#include <iostream>
#define MOD 15746

using namespace std;

int cache[1000001];

int count(int n) {
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	int& ret = cache[n];
	if (ret != -1)
		return ret;

	return ret = (count(n - 1) + count(n - 2)) % MOD;
}

int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < 1000001; i++)
		cache[i] = -1;
	cout << count(n) << endl;
	return 0;
}
