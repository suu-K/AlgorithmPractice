/*
���� : A+B -4(https://www.acmicpc.net/problem/10951)
 �� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 �Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�.
 �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, �� �ٿ� A�� B�� �־�����. (0 < A, B < 10)

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
	while (cin >> a >> b) {
		cout << a + b << "\n";
	}
	return 0;
}