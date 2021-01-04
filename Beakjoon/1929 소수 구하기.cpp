/*
���� : �Ҽ� ���ϱ�(https://www.acmicpc.net/problem/1929)

Ǯ��
	ó���� vector�� �̿��ؼ� Ǯ���µ� �ð��ʰ��� �����ȴ�. �����Ҵ� �ϴµ� �ð��� �ɸ� �� �ϴ�.
	�׷��� array�� �ٲ㼭 Ǯ������ ����ð��� Ȯ���� ª������. ������ ������ �ð��ʰ��� ����.
	�̴� ��� �Լ��� cout���� �ؼ� ������ ���̾���. printf�� ����� �ϴ� �ð� �ȿ� ����� �Ǿ���.
 */

#include <iostream>
#include <cmath>

using namespace std;

void func(int a, int b) {
	bool v[1000001];
	for (int i = 2; i < 1000001; i++)
		v[i] = true;
	v[1] = false;
	for (int i = 2; i <= sqrt(b); i++) {
		if (v[i]) {
			for (int j = i + i; j < b + 1; j += i) {
				v[j] = false;
			}
		}
	}
	for (int i = a; i < b + 1; i++)
		if (v[i])
			printf("%d\n", i);
	return;
}

int main() {
	int n = 0, m = 0;
	cin >> m >> n;
	func(m, n);
	return 0;
}
