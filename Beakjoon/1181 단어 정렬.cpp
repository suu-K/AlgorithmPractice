/*
문제 : 단어 정렬(https://www.acmicpc.net/problem/1181)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool inc(string a, string b) {
	if (a.size() < b.size())
		return true;
	else if (a.size() == b.size())
		if (a < b)
			return true;
	return false;
}

int main() {
	int n = 0;
	string s;
	vector<string> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end(), inc);
	for (int i = 0; i < v.size(); i++) {
		if (i != v.size() - 1 && v[i] == v[i + 1])
			continue;
		cout << v[i] << endl;
	}
	return 0;
}
