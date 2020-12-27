/*
문제 : 수 정렬하기(https://www.acmicpc.net/problem/2750)
 N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다.
 이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

 풀이
  입력으로 주어진 수의 개수가 비교적 적으므로 O(n^2)의 시간복잡도를 가진 버블 정렬을 이용한다
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
