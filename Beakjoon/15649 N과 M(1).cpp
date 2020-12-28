/*
���� : N�� M(1)(https://www.acmicpc.net/problem/15649)
 �ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����

�Է�
 ù° �ٿ� �ڿ��� N�� M�� �־�����. (1 �� M �� N �� 8)

���
 �� �ٿ� �ϳ��� ������ ������ �����ϴ� ������ ����Ѵ�.
 �ߺ��Ǵ� ������ ���� �� ����ϸ� �ȵǸ�, �� ������ �������� �����ؼ� ����ؾ� �Ѵ�.
 ������ ���� ������ �����ϴ� ������ ����ؾ� �Ѵ�.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<bool> vist(9, false);
vector<int> v;
int n, m;

void printV() {
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	printf("\n");
}

void find(int rest) {
	if (rest == 0 && v.size() == m) {
		printV();
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vist[i])
			continue;
		v.push_back(i);
		vist[i] = true;
		find(rest - 1);
		v.pop_back();
		vist[i] = false;
	}
}

int main() {
	cin >> n >> m;
	find(m);
	return 0;
}