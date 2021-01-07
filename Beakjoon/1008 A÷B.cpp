/*
문제 : A/B(https://www.acmicpc.net/problem/1008)
풀이
 나눗셈 문제이므로 결과값이 실수형일 가능성이 크다.
 이떄 상대오차가 10^-9 이하여야 하므로 소수점 이하 자리수를 15자리까지 출력하게 한다.
*/

#include <iostream>

using namespace std;

int main()
{
	double a = 0;
	double b = 0;
	cin >> a >> b;
	cout.precision(15);
	cout << a / b << endl;
	return 0;
}