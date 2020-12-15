/*
���� : ũ�ξ�Ƽ�� ���ĺ�(https://www.acmicpc.net/problem/2941)
 �������� �ü������ ũ�ξ�Ƽ�� ���ĺ��� �Է��� ���� ������. ����, ������ ���� ũ�ξ�Ƽ�� ���ĺ��� �����ؼ� �Է��ߴ�.
 ũ�ξ�Ƽ�� ���ĺ�	����
 ?					c=
 ?					c-
 d?					dz=
 ��					d-
 lj					lj
 nj					nj
 ?					s=
 ?					z=
 ���� ���, ljes=njak�� ũ�ξ�Ƽ�� ���ĺ� 6��(lj, e, ?, nj, a, k)�� �̷���� �ִ�.
 �ܾ �־����� ��, �� ���� ũ�ξ�Ƽ�� ���ĺ����� �̷���� �ִ��� ����Ѵ�.
 d?�� ������ �ϳ��� ���ĺ����� ���̰�, d�� ?�� �и��� ������ ���� �ʴ´�.
 lj�� nj�� ���������̴�. �� ��Ͽ� ���� ���ĺ��� �� ���ھ� ����.

�Է�
 ù° �ٿ� �ִ� 100������ �ܾ �־�����. ���ĺ� �ҹ��ڿ� '-', '='�θ� �̷���� �ִ�.
 �ܾ�� ũ�ξ�Ƽ�� ���ĺ����� �̷���� �ִ�. ���� ������ ǥ�� �����ִ� ���ĺ��� ����� ���·� �Էµȴ�.

���
 �Է����� �־��� �ܾ �� ���� ũ�ξ�Ƽ�� ���ĺ����� �̷���� �ִ��� ����Ѵ�.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string word;
	int num = 0;
	cin >> word;
	for (int i = 0; i < word.size(); i++) {
		switch (word[i]) {
		case 'c':
			if (word[i + 1] == '=' || word[i + 1] == '-')
				i++;
			num++; break;
		case 'd':
			if (word[i + 1] == '-')
				i++;
			else if (word[i + 1] == 'z' && word[i + 2] == '=')
				i += 2;
			num++; break;
		case 'l': case 'n':
			if (word[i + 1] == 'j')
				i++;
			num++; break;
		case 's': case 'z':
			if (word[i + 1] == '=')
				i++;
			num++; break;
		default:
			num++;
		}
	}
	cout << num << endl;
	return 0;
}