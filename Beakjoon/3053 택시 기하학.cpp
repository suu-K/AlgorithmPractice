/*
문제 : 택시 기하학(https://www.acmicpc.net/problem/3053)
 */

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;


int main() {
	int r = 0;
	cin >> r;
	cout << fixed;
	cout.precision(4);
	cout << r * r * M_PI << endl;
	cout << r * r * 2 << endl;
	return 0;
}
