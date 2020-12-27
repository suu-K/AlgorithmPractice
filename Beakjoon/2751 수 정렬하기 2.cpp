/*
���� : �� �����ϱ� 2(https://www.acmicpc.net/problem/2751)
 N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
 ù° �ٿ� ���� ���� N(1 �� N �� 1,000,000)�� �־�����.
 ��° �ٺ��� N���� �ٿ��� ���ڰ� �־�����. �� ���� ������ 1,000,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

���
 ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.

 Ǯ��
 �־����� ���� ������ ���� ũ�Ƿ� �ð����⵵ O(nlogn)�� �ð����⵵�� ������ �� ������ �̿��Ͽ� Ǭ��.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n = 0, tmp = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}
	return 0;
}
