/*
문제 : A/B(https://www.acmicpc.net/problem/1008)
 두 정수 A와 B를 입력받은 다음, A/B를 출력하는 프로그램을 작성하시오.

입력
 첫째 줄에 A와 B가 주어진다. (0 < A, B < 10)

출력
 첫째 줄에 A/B를 출력한다.
 실제 정답과 출력값의 절대오차 또는 상대오차가 10-9 이하이면 정답이다.

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