/*
문제 : 이항 계수 3(https://www.acmicpc.net/problem/11401)

코멘트
	일반적인 이항 계수의 정의 및 성질 만으로는 시간 안에 풀 수 없는 문제였다.
	페르마의 소정리를 이용해야 했다.
 */

#include <iostream>
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll fac[4000001];

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

ll power(ll a, ll b) {
	if (b == 0) return 1;
	if (b % 2 == 1)
		return (power(a, b - 1) * a) % MOD;
	ll k = power(a, b / 2) % MOD;
	return (k * k) % MOD;
}

ll bin(int n, int k) {
	ll a = fac[n];
	ll b = (fac[k] * fac[n - k]) % MOD;
	ll b2 = power(b, MOD - 2);
	return (a * b2) % MOD;
}

int main() {
	init();
	int n, k;
	cin >> n >> k;
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = (fac[i - 1] * i) % MOD;
	}
	cout << bin(n, k) << endl;

	return 0;
}