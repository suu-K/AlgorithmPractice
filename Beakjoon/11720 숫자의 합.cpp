/*
���� : ������ �� (https://www.acmicpc.net/problem/11720)
 N���� ���ڰ� ���� ���� �����ִ�. �� ���ڸ� ��� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 ù° �ٿ� ������ ���� N (1 �� N �� 100)�� �־�����. ��° �ٿ� ���� N���� ������� �־�����.

���
 �Է����� �־��� ���� N���� ���� ����Ѵ�.
*/

#include <iostream>

using namespace std;

int main() {
	int n = 0, sum = 0;
	string str;
	cin >> n >> str;
	for (int i = 0; i < n; i++) {
		sum += (int)str[i] - '0';
	}
	cout << sum << endl;
	return 0;
}
