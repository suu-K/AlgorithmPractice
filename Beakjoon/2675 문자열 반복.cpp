/*
���� : ���ڿ� �ݺ� (https://www.acmicpc.net/problem/2675)
 ���ڿ� S�� �Է¹��� �Ŀ�, �� ���ڸ� R�� �ݺ��� �� ���ڿ� P�� ���� �� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
 ��, ù ��° ���ڸ� R�� �ݺ��ϰ�, �� ��° ���ڸ� R�� �ݺ��ϴ� ������ P�� ����� �ȴ�. S���� QR Code "alphanumeric" ���ڸ� ����ִ�.
 QR Code "alphanumeric" ���ڴ� 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: �̴�.

�Է�
 ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1 �� T �� 1,000)�� �־�����.

 �� �׽�Ʈ ���̽��� �ݺ� Ƚ�� R(1 �� R �� 8), ���ڿ� S�� �������� ���еǾ� �־�����.
 S�� ���̴� ��� 1�̸�, 20���ڸ� ���� �ʴ´�.

���
 �� �׽�Ʈ ���̽��� ���� P�� ����Ѵ�.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	int n;
	string word;
	string tmp;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> word;
		for (int j = 0; j < word.size(); j++) {
			for (int k = 0; k < n; k++) {
				tmp.push_back(word[j]);
			}
		}
		cout << tmp << endl;
		word.clear();
		tmp.clear();
	}

	return 0;
}