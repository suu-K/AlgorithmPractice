/*
문제 : 한수 (https://www.acmicpc.net/problem/1065)
 어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다.
 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.

입력
 첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.

출력
 첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.
*/

#include <iostream>
#include <vector>

using namespace std;

bool func(int n) {
	vector<int> v;
	int num = n, d = 0, nd = 0;
	while (num != 0) {
		v.push_back(num % 10);
		num /= 10;
	}
	if (v.size() < 3)
		return true;
	d = v[1] - v[0];
	for (int i = 0; i < v.size() - 1; i++) {
		if (d != (nd = v[i + 1] - v[i]))
			return false;
		d = nd;
	}
	return true;
}

int main() {
	int n = 0;
	int num = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (func(i))
			num++;
	}
	cout << num << endl;
	return 0;
}
