/*
문제 : 두 수 비교하기(https://www.acmicpc.net/problem/1330)
*/

#include <iostream>

using namespace std;

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;

	if (a > b)
		cout << ">" << endl;
	else if (a < b)
		cout << "<" << endl;
	else
		cout << "==" << endl;
	return 0;
}