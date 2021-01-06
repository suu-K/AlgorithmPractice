/*
���� : ������(https://www.acmicpc.net/problem/2565)

Ǯ��
	�������� ������ a�� 1�� ��ġ���� ���ʴ�� ���ڸ� �ᱹ �������� ū ���� ����Ǿ� �־�� �Ѵ�.
	�̴� ������ b�� ���� �κ� ������ ����. ���� �������� �ּҷ� ���ֱ� ���ؼ� ���� �� ���� �κ� ������ ã���� �ȴ�.
	������ ó���� �������� �־��� �� ������� �־����� �����Ƿ� ������ a�� �������� ���� �� �� ������ b�� �ִ� ���� �κ� ������ ã�´�.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pole {
	int a;
	int b;
	pole(int a, int b) : a(a), b(b) {};
}typedef pole;

int a[101];		//������ �����ϴ� �迭
int cache[101];	//�κ� �������� �޸������̼� �� �迭
int n;				//�־��� ������ ����

int lis(int idx) {	//�ִ� ������ �κ� ���� ����
	if (idx > n)
		return 0;

	int& ret = cache[idx];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int next = idx + 1; next <= n; next++) {
		if (a[next] > a[idx])
			ret = max(ret, lis(next) + 1);
	}

	return ret;
}

void reset() {
	for (int i = 0; i < 101; i++)
		cache[i] = -1;
}

bool inc(pole a, pole b) {	//a�������� ������� ����
	if (a.a < b.a)
		return true;
	else
		return false;
}


int main() {
	int an, bn;
	vector<pole> v;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> an >> bn;
		v.push_back(pole(an, bn));
	}
	reset();

	sort(v.begin(), v.end(), inc);

	a[0] = 0;						//���ĵ� ������ �ű�
	for (int i = 1; i <= n; i++) {
		a[i] = v[i - 1].b;
	}


	cout << n - lis(0) << endl;		//�������� ��ü �������� �ִ� ���� �κ� ������ ���� ���־� �� �������� ��

	return 0;
}