/*
���� : �� �����ϱ�(https://www.acmicpc.net/problem/2750)

 Ǯ��
	�Է����� �־��� ���� ������ ���� �����Ƿ� O(n^2)�� �ð����⵵�� ���� ���� ������ �̿��Ѵ�
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0, tmp = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = i; j < v.size(); j++) {
			if (v[i] > v[j]) {
				tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}
