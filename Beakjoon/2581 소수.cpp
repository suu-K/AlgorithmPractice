/*
���� : �Ҽ�(https://www.acmicpc.net/problem/2581)
 �ڿ��� M�� N�� �־��� �� M�̻� N������ �ڿ��� �� �Ҽ��� ���� ��� ��� �̵� �Ҽ��� �հ� �ּڰ��� ã�� ���α׷��� �ۼ��Ͻÿ�.
 ���� ��� M=60, N=100�� ��� 60�̻� 100������ �ڿ��� �� �Ҽ��� 61, 67, 71, 73, 79, 83, 89, 97 �� 8���� �����Ƿ�, �̵� �Ҽ��� ���� 620�̰�, �ּڰ��� 61�� �ȴ�.

�Է�
 �Է��� ù° �ٿ� M��, ��° �ٿ� N�� �־�����.
 M�� N�� 10,000������ �ڿ����̸�, M�� N���� �۰ų� ����.

���
 M�̻� N������ �ڿ��� �� �Ҽ��� ���� ��� ã�� ù° �ٿ� �� ����, ��° �ٿ� �� �� �ּڰ��� ����Ѵ�.
 ��, M�̻� N������ �ڿ��� �� �Ҽ��� ���� ���� ù° �ٿ� -1�� ����Ѵ�.
 */

#include <iostream>
#include <cmath>

using namespace std;

void func(int a, int b) {
	int sum = 0, m = b + 1;
	bool isPrime = true;
	for (int i = a; i <= b; i++) {
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime && i != 1) {
			sum += i;
			m = min(m, i);
		}
		isPrime = true;
	}
	if (m == b + 1) {
		cout << -1;
		return;
	}
	cout << sum << endl;
	cout << m << endl;
}

int main() {
	int n = 0, m = 0;
	cin >> m >> n;
	func(m, n);
	return 0;
}
