/*
���� : �ܾ� ����(https://www.acmicpc.net/problem/1181)
 ���ĺ� �ҹ��ڷ� �̷���� N���� �ܾ ������ �Ʒ��� ���� ���ǿ� ���� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	1. ���̰� ª�� �ͺ���
	2. ���̰� ������ ���� ������

�Է�
 ù° �ٿ� �ܾ��� ���� N�� �־�����. (1 �� N �� 20,000)
 ��° �ٺ��� N���� �ٿ� ���� ���ĺ� �ҹ��ڷ� �̷���� �ܾ �� �ٿ� �ϳ��� �־�����.
 �־����� ���ڿ��� ���̴� 50�� ���� �ʴ´�.

���
 ���ǿ� ���� �����Ͽ� �ܾ���� ����Ѵ�.
 ��, ���� �ܾ ���� �� �Էµ� ��쿡�� �� ������ ����Ѵ�.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool inc(string a, string b) {
	if (a.size() < b.size())
		return true;
	else if (a.size() == b.size())
		if (a < b)
			return true;
	return false;
}

int main() {
	int n = 0;
	string s;
	vector<string> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), inc);
	for (int i = 0; i < v.size(); i++) {
		if (i != v.size() - 1 && v[i] == v[i + 1])
			continue;
		cout << v[i] << endl;
	}
	return 0;
}
