/*
¹®Á¦ : N°ú M(2)(https://www.acmicpc.net/problem/15650)
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
	vector<int> idx;
	for (int i = 1; i <= n; i++) {
		if (vist[i])
			continue;
		v.push_back(i);
		vist[i] = true;
		find(rest - 1);
		v.pop_back();
		idx.push_back(i);
	}
	for (int i = 0; i < idx.size(); i++)
		vist[idx[i]] = false;
}

int main() {
	cin >> n >> m;
	find(m);
	return 0;
}