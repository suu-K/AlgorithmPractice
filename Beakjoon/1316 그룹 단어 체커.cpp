/*
���� : �׷� �ܾ� üĿ(https://www.acmicpc.net/problem/1316)
 �׷� �ܾ�� �ܾ �����ϴ� ��� ���ڿ� ���ؼ�, �� ���ڰ� �����ؼ� ��Ÿ���� ��츸�� ���Ѵ�.
 ���� ���, ccazzzzbb�� c, a, z, b�� ��� �����ؼ� ��Ÿ����, kin�� k, i, n�� �����ؼ� ��Ÿ���� ������ �׷� �ܾ�������, aabbbccb�� b�� �������� ��Ÿ���� ������ �׷� �ܾ �ƴϴ�.
 �ܾ� N���� �Է����� �޾� �׷� �ܾ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 ù° �ٿ� �ܾ��� ���� N�� ���´�. N�� 100���� �۰ų� ���� �ڿ����̴�.
 ��° �ٺ��� N���� �ٿ� �ܾ ���´�
 �ܾ�� ���ĺ� �ҹ��ڷθ� �Ǿ��ְ� �ߺ����� ������, ���̴� �ִ� 100�̴�.

���
 ù° �ٿ� �׷� �ܾ��� ������ ����Ѵ�.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int checker(string word) {
	vector<bool> a(26, false);
	for (int i = 0; i < word.size(); i++) {
		if (a[word[i] - 'a'] == true)
			return 0;
		if (word[i] != word[i + 1])
			a[word[i] - 'a'] = true;
	}
	return 1;
}

int main() {
	int t, num = 0;
	string word;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> word;
		num += checker(word);
	}
	cout << num << endl;
	return 0;
}