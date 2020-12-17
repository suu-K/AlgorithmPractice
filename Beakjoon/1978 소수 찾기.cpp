/*
���� : �Ҽ� ã��(https://www.acmicpc.net/problem/1978)
 �־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 ù �ٿ� ���� ���� N�� �־�����. N�� 100�����̴�. �������� N���� ���� �־����µ� ���� 1,000 ������ �ڿ����̴�.

���
 �־��� ���� �� �Ҽ��� ������ ����Ѵ�.
 */

#include <iostream>
#include <cmath>

using namespace std;

bool func(int n) {
	if (n == 1)
		return false;
	bool ok = true;
	int sq = sqrt(n);
	for (int i = 2; i <= sq; i++) {
		if ((n % i) == 0) {
			ok = false;
			break;
		}
	}
	return ok;
}

int main() {
	int n = 0, num = 0, count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (func(num)) count++;
	}
	cout << count << endl;
	return 0;
}
