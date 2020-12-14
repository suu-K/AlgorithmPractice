/*
���� : ���̾�(https://www.acmicpc.net/problem/5622)
 ������� �ҸӴϴ� �Ʒ� �׸��� ���� ������ ���̾� ��ȭ�⸦ ����Ѵ�.
 ��ȭ�� �ɰ� ���� ��ȣ�� �ִٸ�, ���ڸ� �ϳ��� ���� ������ �ݼ� ���� �ִ� �� ���� �ð�������� ������ �Ѵ�.
 ���ڸ� �ϳ� ������ ���̾��� ó�� ��ġ�� ���ư���, ���� ���ڸ� �������� ���̾��� ó�� ��ġ���� �ٽ� ������ �Ѵ�.
 ���� 1�� �ɷ��� �� 2�ʰ� �ʿ��ϴ�. 1���� ū ���� �Ŵµ� �ɸ��� �ð��� �̺��� �� �ɸ���, �� ĭ ���� �ִ� ���ڸ� �ɱ� ���ؼ� 1�ʾ� �� �ɸ���.
 ������� �ҸӴϴ� ��ȭ ��ȣ�� �� ���ڿ� �ش��ϴ� ���ڷ� �ܿ��.
 ��, � �ܾ �� ��, �� ���ĺ��� �ش��ϴ� ���ڸ� �ɸ� �ȴ�. ���� ���, UNUCIC�� 868242�� ����.
 �ҸӴϰ� �ܿ� �ܾ �־����� ��, �� ��ȭ�� �ɱ� ���ؼ� �ʿ��� �ּ� �ð��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 ù° �ٿ� ���ĺ� �빮�ڷ� �̷���� �ܾ �־�����. �ܾ�� 2����~15���ڷ� �̷���� �ִ�.

���
 ù° �ٿ� ���̾��� �ɱ� ���ؼ� �ʿ��� �ּ� �ð��� ����Ѵ�.
*/

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	string word;
	int sec = 0;
	cin >> word;
	for (int i = 0; i < word.size(); i++) {
		switch (word[i]) {
		case 'A': case 'B': case 'C':
			sec += 2;
			break;
		case 'D': case 'E': case 'F':
			sec += 3;
			break;
		case 'G': case 'H': case 'I':
			sec += 4;
			break;
		case 'J': case 'K': case 'L':
			sec += 5;
			break;
		case 'M': case 'N': case 'O':
			sec += 6;
			break;
		case 'P': case 'Q': case 'R': case 'S':
			sec += 7;
			break;
		case 'T': case 'U': case 'V':
			sec += 8;
			break;
		case 'W': case 'X': case 'Y': case 'Z':
			sec += 9;
			break;
		}
	}

	cout << sec + word.size() << endl;
	return 0;
}