/*
���� : �� �� ���ϱ�(https://www.acmicpc.net/problem/1330)
 �� ���� A�� B�� �־����� ��, A�� B�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Է�
 ù° �ٿ� A�� B�� �־�����. A�� B�� ���� �� ĭ���� ���еǾ��� �ִ�.

���
 ù° �ٿ� ���� �� ���� �� �ϳ��� ����Ѵ�.
	A�� B���� ū ��쿡�� '>'�� ����Ѵ�.
	A�� B���� ���� ��쿡�� '<'�� ����Ѵ�.
	A�� B�� ���� ��쿡�� '=='�� ����Ѵ�.

*/

#include <iostream>

using namespace std;

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;

	if (a > b)
		cout << ">" << endl;
	else if (a < b)
		cout << "<" << endl;
	else
		cout << "==" << endl;
	return 0;
}