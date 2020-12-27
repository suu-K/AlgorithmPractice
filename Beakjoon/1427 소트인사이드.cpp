/*
문제 : 소트인사이드(https://www.acmicpc.net/problem/1427)
 배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.

입력
 첫째 줄에 정렬하고자하는 수 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.

출력
 첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n = 0;
	int ret = 0;
	vector<int> v;
	cin >> n;
	while (n > 0) {
		v.push_back(n % 10);
		n /= 10;
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size(); i++) {
		ret = ret * 10 + v[i];
	}
	cout << ret << endl;
	return 0;
}
