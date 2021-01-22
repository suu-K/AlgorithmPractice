/*
문제 : 요세푸스 문제 0(https://www.acmicpc.net/problem/11866)
 */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list<int> ls;
	list<int>::iterator it;
	vector<int> v;
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		ls.push_back(i);

	it = ls.begin();

	while (!ls.empty()) {
		for (int i = 0; i < k - 1; i++) {
			it++;
			if (it == ls.end())
				it = ls.begin();
		}
		v.push_back(*it);
		it = ls.erase(it);
		if (it == ls.end())
			it = ls.begin();
	}

	cout << "<";
	for (int i = 0; i < v.size() - 1; i++) {
		cout << v[i] << ", ";
	}
	cout << v.back() << ">" << endl;

	return 0;
}