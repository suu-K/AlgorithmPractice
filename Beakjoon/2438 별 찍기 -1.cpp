/*
���� : �� ��� -1(https://www.acmicpc.net/problem/2438)
 ù° �ٿ��� �� 1��, ��° �ٿ��� �� 2��, N��° �ٿ��� �� N���� ��� ����

�Է�
 ù° �ٿ� N(1 �� N �� 100)�� �־�����.

���
 ù° �ٺ��� N��° �ٱ��� ���ʴ�� ���� ����Ѵ�.
*/

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++)
			cout << "*";
		cout << "\n";
	}

	return 0;
}