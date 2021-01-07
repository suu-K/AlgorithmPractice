/*
문제 : 손익 분기점(https://www.acmicpc.net/problem/1712)
 */

#include <iostream>

using namespace std;

int main() {
	int sum = 0, n = 0;;
	int price, fcost, vcost;
	cin >> fcost >> vcost >> price;
	if (vcost >= price)
		n = -1;
	else {
		n = fcost / (price - vcost) + 1;
	}
	cout << n << endl;
	return 0;
}