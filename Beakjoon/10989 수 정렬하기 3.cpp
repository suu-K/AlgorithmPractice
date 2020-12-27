/*
문제 : 수 정렬하기 3(https://www.acmicpc.net/problem/10989)
 N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
 첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다.
 이 수는 10,000보다 작거나 같은 자연수이다.

출력
 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

 풀이
 주어지는 수의 범위가 비교적 작으므로 카운팅 정렬을 이용한다.
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
