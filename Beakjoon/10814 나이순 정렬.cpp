/*
���� : ���̼� ����(https://www.acmicpc.net/problem/10814)
 �¶��� ������ ������ ������� ���̿� �̸��� ������ ������� �־�����.
 �̶�, ȸ������ ���̰� �����ϴ� ������, ���̰� ������ ���� ������ ����� �տ� ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 ù° �ٿ� �¶��� ���� ȸ���� �� N�� �־�����. (1 �� N �� 100,000)
 ��° �ٺ��� N���� �ٿ��� �� ȸ���� ���̿� �̸��� �������� ���еǾ� �־�����.
 ���̴� 1���� ũ�ų� ������, 200���� �۰ų� ���� �����̰�, �̸��� ���ĺ� ��ҹ��ڷ� �̷���� �ְ�, ���̰� 100���� �۰ų� ���� ���ڿ��̴�.
 �Է��� ������ ������ �־�����.

���
 ù° �ٺ��� �� N���� �ٿ� ���� �¶��� ���� ȸ���� ���� ��, ���̰� ������ ������ ������ �� �ٿ� �� �� ���̿� �̸��� �������� ������ ����Ѵ�.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct member {
	int age;
	string name;
	int no;
	member(int age, string name, int no) : age(age), name(name), no(no) {};
}typedef member;

bool inc(member a, member b) {
	if (a.age < b.age)
		return true;
	else if (a.age == b.age)
		if (a.no < b.no)
			return true;
	return false;
}

int main() {
	int n = 0, tmp = 0;
	string name;
	vector<member> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp >> name;
		v.push_back(member(tmp, name, i));
	}
	sort(v.begin(), v.end(), inc);
	for (int i = 0; i < v.size(); i++) {
		printf("%d %s\n", v[i].age, v[i].name.c_str());
	}
	return 0;
}
