/*
���� : �ִ� (https://www.acmicpc.net/problem/2562)
 9���� ���� �ٸ� �ڿ����� �־��� ��, �̵� �� �ִ��� ã�� �� �ִ��� �� ��° �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
 ���� ���, ���� �ٸ� 9���� �ڿ��� 3, 29, 38, 12, 57, 74, 40, 85, 61 �� �־�����, �̵� �� �ִ��� 85�̰�, �� ���� 8��° ���̴�.

�Է�
 ù° �ٺ��� ��ȩ ��° �ٱ��� �� �ٿ� �ϳ��� �ڿ����� �־�����. �־����� �ڿ����� 100 ���� �۴�.

���
 ù° �ٿ� �ִ��� ����ϰ�, ��° �ٿ� �ִ��� �� ��° �������� ����Ѵ�.
*/

#include <iostream>

using namespace std;

int main() {
	int maximum = 0, idx = 0;
	int tmp;
	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		maximum = max(maximum, tmp);
		if (tmp == maximum)
			idx = i + 1;
	}

	cout << maximum << endl << idx << endl;


	return 0;
}