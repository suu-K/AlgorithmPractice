/*
문제 : 상수(https://www.acmicpc.net/problem/2908)
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string a, b;
	int na, nb;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	na = stoi(a);
	nb = stoi(b);
	if (na > nb)
		cout << na << endl;
	else
		cout << nb << endl;
	return 0;
}