/*
문제 : 소수 구하기(https://www.acmicpc.net/problem/1929)

풀이
	처음에 vector를 이용해서 풀었는데 시간초과가 나버렸다. 동적할당 하는데 시간이 걸린 듯 하다.
	그래서 array로 바꿔서 풀었더니 수행시간이 확실히 짧아졌다. 하지만 여전히 시간초과가 났다.
	이는 출력 함수를 cout으로 해서 벌어진 일이었다. printf로 출력을 하니 시간 안에 출력이 되었다.
 */

#include <iostream>
#include <cmath>

using namespace std;

void func(int a, int b) {
	bool v[1000001];
	for (int i = 2; i < 1000001; i++)
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
			printf("%d\n", i);
	return;
}

int main() {
	int n = 0, m = 0;
	cin >> m >> n;
	func(m, n);
	return 0;
}
