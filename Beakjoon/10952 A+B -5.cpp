/*
���� : A+B -5(https://www.acmicpc.net/problem/10952)
 �� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 �Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�.
 �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, �� �ٿ� A�� B�� �־�����. (0 < A, B < 10)
 �Է��� ���������� 0 �� ���� ���´�.

���
 �� �׽�Ʈ ���̽����� A+B�� ����Ѵ�.
*/

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a = 0, b = 0;
	cin >> a >> b;
	while (a != 0 || b != 0) {
		cout << a + b << "\n";
		cin >> a >> b;		
	}
	return 0;
}