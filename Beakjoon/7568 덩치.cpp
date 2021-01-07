/*
문제 : 덩치(https://www.acmicpc.net/problem/7568)
 */

#include <iostream>
#include <vector>

using namespace std;

struct person {
	int w;
	int h;
	int rank;
	person(int w, int h, int rank) : w(w), h(h), rank(rank) {};
}typedef person;

int main() {
	int n = 0;
	int tw = 0, th = 0;
	vector<person> p;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tw >> th;
		p.push_back(person(tw, th, 0));
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (p[i].w > p[j].w && p[i].h > p[j].h) {
				p[j].rank++;
			}
			else if (p[i].w < p[j].w && p[i].h < p[j].h) {
				p[i].rank++;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << p[i].rank + 1 << " ";
	cout << endl;
	return 0;
}