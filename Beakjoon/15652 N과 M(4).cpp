/*
¹®Á¦ : N°ú M(4)(https://www.acmicpc.net/problem/15652)
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n, m;

void printV() {
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	printf("\n");
}

void find(int idx, int rest) {
	if (rest == 0 && v.size() == m) {
		printV();
		return;
	}
	for (int i = idx; i <= n; i++) {
		v.push_back(i);
		find(i, rest - 1);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	find(1, m);
	return 0;
}