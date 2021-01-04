/*
문제 : 수 정렬하기 3(https://www.acmicpc.net/problem/10989)
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 0, tmp = 0;
	vector<int> v(10001, 0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &tmp);
		v[tmp]++;
	}
	for (int i = 1; i < v.size(); i++) {
		for (int j = 0; j < v[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}
