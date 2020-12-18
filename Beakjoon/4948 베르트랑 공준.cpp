/*
문제 : 베르트랑 공준(https://www.acmicpc.net/problem/4948)
 베르트랑 공준은 임의의 자연수 n에 대하여, n보다 크고, 2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고 있다.
 이 명제는 조제프 베르트랑이 1845년에 추측했고 파프누티 체비쇼프가 1850년에 증명했다.
 예를 들어, 10보다 크로 20보다 작거나 같은 소수는 4개가 있다.(11, 13, 17, 19) 또, 14보다 크로, 28보다 작거나 같은 소수는 3개가 있다.(17, 19, 23)
 자연수 n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오.

입력
 입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 케이스는 n을 포함하며, 한 줄로 이루어져 있다. (n ≤ 123456)
 입력의 마지막에는 0이 주어진다.

출력
 각 테스트 케이스에 대해서, n보다 크고, 2n보다 작거나 같은 소수의 개수를 출력한다.
 */

#include <iostream>
#include <cmath>

using namespace std;

void func(int a, int b) {
	int count = 0;
	int v[123456 * 2 + 1];
	for (int i = 2; i < 123456 * 2 + 1; i++)
		v[i] = true;
	v[1] = false;
	for (int i = 2; i <= sqrt(b); i++) {
		if (v[i]) {
			for (int j = i + i; j < b + 1; j += i) {
				v[j] = false;
			}
		}
	}
	for (int i = a; i < b + 1; i++)
		if (v[i])
			count++;
	printf("%d\n", count);
	return;
}

int main() {
	int n = 1;
	cin >> n;
	while (n != 0) {
		func(n + 1, 2 * n);
		cin >> n;
	}
	return 0;
}
