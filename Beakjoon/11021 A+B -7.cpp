/*
���� : A+B -7(https://www.acmicpc.net/problem/11021)
 �� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.
 �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, �� �ٿ� A�� B�� �־�����. (0 < A, B < 10)

���
 �� �׽�Ʈ ���̽����� "Case #x: "�� ����� ����, A+B�� ����Ѵ�.
 �׽�Ʈ ���̽� ��ȣ�� 1���� �����Ѵ�.
*/

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	int a=0, b=0;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> a >> b;
		cout << "Case #" << i << ": " << a + b << "\n";
	}

	return 0;
}