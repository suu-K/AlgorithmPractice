/*
���� : ������(https://www.acmicpc.net/problem/2739)
 N�� �Է¹��� ��, ������ N���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��� ���Ŀ� ���缭 ����ϸ� �ȴ�.

�Է�
 ù° �ٿ� N�� �־�����. N�� 1���� ũ�ų� ����, 9���� �۰ų� ����.

���
 ������İ� ���� N*1���� N*9���� ����Ѵ�.

*/

#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= 9; i++)
		cout << n << " * " << i << " = " << n * i << endl;
	return 0;
}