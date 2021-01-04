/*
문제 : 숫자의 개수 (https://www.acmicpc.net/problem/2577)
*/

#include <iostream>

using namespace std;

int main() {
	int a = 0, b = 0, c = 0;
	int mul;
	int arr[10] = { 0 };
	cin >> a >> b >> c;
	mul = a * b * c;
	while (mul != 0) {
		arr[mul % 10]++;
		mul = mul / 10;
	}
	for (int i = 0; i < 10; i++)
		cout << arr[i] << endl;


	return 0;
}