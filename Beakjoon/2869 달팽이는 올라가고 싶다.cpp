/*
���� : �����̴� �ö󰡰� �ʹ�(https://www.acmicpc.net/problem/2869)
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int a, b, v;
	int sum = 0, day = 1;
	cin >> a >> b >> v;
	day += ceil((double)(v - a) / (a - b));
	cout << day << endl;
	return 0;
}