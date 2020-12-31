/*
문제 : 피보나치 수 2(https://www.acmicpc.net/problem/2748)
 피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.
 이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n ≥ 2)가 된다.
 n=17일때 까지 피보나치 수를 써보면 다음과 같다.

	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

 n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.

입력
 첫째 줄에 n이 주어진다. n은 90보다 작거나 같은 자연수이다.

출력
 첫째 줄에 n번째 피보나치 수를 출력한다.

풀이
 주어지는n이 커지면 4바이트의 int형으로는 모두 담아낼 수 없으므로 long long을 이용했다.
 */

#include <iostream>

using namespace std;

long long cache[90];

long long fibo(int n) {
	if (n == 0)
		return cache[n] = 0;
	if (n == 1)
		return cache[n] = 1;
	long long& ret = cache[n];
	if (ret != 0)
		return ret;
	return ret = fibo(n - 2) + fibo(n - 1);
}

int main() {
	int n = 0;
	cin >> n;
	cout << fibo(n) << endl;
	return 0;
}
