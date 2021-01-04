/*
문제 : 수 정렬하기(https://www.acmicpc.net/problem/2750)

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
