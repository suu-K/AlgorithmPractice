/*
���� : �Ǻ���ġ �� 2(https://www.acmicpc.net/problem/2748)
 �Ǻ���ġ ���� 0�� 1�� �����Ѵ�. 0��° �Ǻ���ġ ���� 0�̰�, 1��° �Ǻ���ġ ���� 1�̴�. �� ���� 2��° ���ʹ� �ٷ� �� �� �Ǻ���ġ ���� ���� �ȴ�.
 �̸� ������ �Ẹ�� Fn = Fn-1 + Fn-2 (n �� 2)�� �ȴ�.
 n=17�϶� ���� �Ǻ���ġ ���� �Ẹ�� ������ ����.

	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

 n�� �־����� ��, n��° �Ǻ���ġ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 ù° �ٿ� n�� �־�����. n�� 90���� �۰ų� ���� �ڿ����̴�.

���
 ù° �ٿ� n��° �Ǻ���ġ ���� ����Ѵ�.

Ǯ��
 �־�����n�� Ŀ���� 4����Ʈ�� int�����δ� ��� ��Ƴ� �� �����Ƿ� long long�� �̿��ߴ�.
 */

#include <iostream>

using namespace std;

long long cache[90];

long long fibo(int n) {
	if (n == 0)
		return cache[n] = 0;
	if (n == 1)
		return cache[n] = 1;
	long long& ret = cache[n];
	if (ret != 0)
		return ret;
	return ret = fibo(n - 2) + fibo(n - 1);
}

int main() {
	int n = 0;
	cin >> n;
	cout << fibo(n) << endl;
	return 0;
}
