/*
���� : �ϳ��� ž �̵� ����(https://www.acmicpc.net/problem/11729)
 */

#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int a, int b, int c, int n) {	//n���� ������ a���뿡�� c����� �ű�� �Լ�
	if (n == 1) {
		printf("\n%d %d", a, c);
		return;
	}

	hanoi(a, c, b, n - 1);	//a���� b�� n-1���� �ű��.
	printf("\n%d %d", a, c);		//a���� c�� 1���� �ű��.
	hanoi(b, a, c, n - 1);	//b���� c�� n-1���� �ű��.
	return;
}


int main() {
	int n = 0;
	cin >> n;
	cout << (int)pow(2, n) - 1;
	hanoi(1, 2, 3, n);
	return 0;
}