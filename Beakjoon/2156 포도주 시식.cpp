/*
문제 : 포도주 시식(https://www.acmicpc.net/problem/2156)
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> glass;
int cache[10001];

int main() {
	int n = 0;
	int tmp = 0;

	cin >> n;
	glass.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		glass.push_back(tmp);
	}
	cache[1] = glass[1];
	cache[2] = glass[1] + glass[2];
	cache[3] = max(cache[2], glass[1] + glass[3]);
	cache[3] = max(cache[3], glass[2] + glass[3]);

	for (int i = 4; i <= n; i++) {
		cache[i] = max(cache[i - 1], cache[i - 2] + glass[i]);
		cache[i] = max(cache[i], cache[i - 3] + glass[i - 1] + glass[i]);
	}

	cout << cache[n] << endl;

	return 0;
}