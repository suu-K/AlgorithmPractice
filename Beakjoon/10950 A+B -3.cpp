/*
���� : A+B -3(https://www.acmicpc.net/problem/10950)
 �� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.
�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, �� �ٿ� A�� B�� �־�����. (0 < A, B < 10)

���
 �� �׽�Ʈ ���̽����� A+B�� ����Ѵ�.

*/

#include <iostream>

using namespace std;

int main()
{
	int t = 0;
	int a = 0, b = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << a + b << endl;
	}
	return 0;
}