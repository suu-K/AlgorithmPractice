/*
���� : ���� ����(https://www.acmicpc.net/problem/9498)
 ���� ������ �Է¹޾� 90 ~ 100���� A, 80 ~ 89���� B, 70 ~ 79���� C, 60 ~ 69���� D, ������ ������ F�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 ù° �ٿ� ���� ������ �־�����. ���� ������ 0���� ũ�ų� ����, 100���� �۰ų� ���� �����̴�.

���
 ���� ������ ����Ѵ�.

*/

#include <iostream>

using namespace std;

int main()
{
	int score = 0;
	cin >> score;

	if (score >= 90)
		cout << "A" << endl;
	else if (score >= 80)
		cout << "B" << endl;
	else if (score >= 70)
		cout << "C" << endl;
	else if (score >= 60)
		cout << "D" << endl;
	else
		cout << "F" << endl;
	return 0;
}