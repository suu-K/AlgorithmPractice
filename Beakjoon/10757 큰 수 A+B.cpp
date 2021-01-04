/*
문제 : 큰 수 A+B(https://www.acmicpc.net/problem/10757)

풀이
	입력으로 주어지는 수의 자릿수가 일반적인 자료형이 받아들일 수 있는 크기보다 크므로 배열을 이용해 계산을 해야 한다.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int>& a, vector<int>& b) {
	if (a.size() < b.size())
		add(b, a);
	vector<int> sum;
	b.resize(a.size());
	for (int i = 0; i < a.size(); i++) {
		sum.push_back(a[i] + b[i]);
	}
	sum.push_back(0);
	for (int i = 0; i < sum.size() - 1; i++) {
		sum[i + 1] += sum[i] / 10;
		sum[i] %= 10;
	}
	if (sum.back() == 0)
		sum.pop_back();
	return sum;
}

int main() {
	vector<int> a;
	vector<int> b;
	string an, bn;
	vector<int> sum;

	cin >> an >> bn;
	for (int i = an.size() - 1; i >= 0; i--)
		a.push_back(an[i] - '0');
	for (int i = bn.size() - 1; i >= 0; i--)
		b.push_back(bn[i] - '0');

	sum = add(a, b);

	for (int i = sum.size() - 1; i >= 0; i--) {
		printf("%d", sum[i]);
	}

	return 0;
}
