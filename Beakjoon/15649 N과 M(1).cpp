/*
문제 : N과 M(1)(https://www.acmicpc.net/problem/15649)
 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
	1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

입력
 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

출력
 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다.
 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
 수열은 사전 순으로 증가하는 순서로 출력해야 한다.
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