/*
���� : ���簢������ Ż��(https://www.acmicpc.net/problem/1085)
 �Ѽ��� ���� (x, y)�� �ִ�. ���簢���� ���� �Ʒ� �������� (0, 0)�� �ְ�, ������ �� �������� (w, h)�� �ִ�.
 ���簢���� ��輱���� ���� �Ÿ��� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 ù° �ٿ� x, y, w, h�� �־�����.

���
 ù° �ٿ� ������ ������ ����Ѵ�.
 */

#include <iostream>

using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int m = 1001;
	m = min(x, y);
	m = min(m, w - x);
	m = min(m, h - y);
	cout << m << endl;
	return 0;
}
