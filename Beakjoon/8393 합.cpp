/*
���� : ��(https://www.acmicpc.net/problem/8393)
 n�� �־����� ��, 1���� n���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 ù° �ٿ� n (1 �� n �� 10,000)�� �־�����.

���
 1���� n���� ���� ����Ѵ�.
*/

#include <iostream>

using namespace std;

int main()
{
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		sum += i;
	cout << sum << endl;
	return 0;
}