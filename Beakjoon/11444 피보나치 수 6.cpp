/*
문제 : 피보나치 수 6(https://www.acmicpc.net/problem/11444)

코멘트
	피보나치 수를 행렬의 제곱 형식으로 나타낼 수 있다.
 */

#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;
typedef vector<vector<long long>> matrix;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

matrix mul(matrix& a, matrix& b) {	//a행렬과 b행렬의 곱
	int y = a.size();
	int x = b[0].size();
	int n = b.size();
	matrix ret(y, vector<long long>(x, 0));

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {

			for (int k = 0; k < n; k++) {
				ret[i][j] += ((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD;
				ret[i][j] %= MOD;
			}
		}
	}
	return ret;
}

matrix power(matrix& a, long long b) {	//a의 b제곱을 구하는 함수
	if (b == 1) {
		int n = a.size();
		matrix ret = a;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				ret[y][x] %= MOD;
			}
		}
		return ret;
	}
	else if (b == 2)
		return mul(a, a);

	matrix half = power(a, b / 2);
	matrix ret = mul(half, half);

	if (b % 2 == 0) {
		return ret;
	}
	else {
		return mul(ret, a);
	}
}

void printMatrix(matrix a) {
	int n = a.size();
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cout << a[y][x] << " ";
		}
		cout << endl;
	}
}

int main() {
	init();
	long long n;
	matrix a;
	matrix ret;
	cin >> n;
	a.push_back(vector<long long>(2, 1));
	a.push_back(vector<long long>(2, 1));
	a[1][1] = 0;
	ret = power(a, n);
	cout << ret[0][1] << endl;

	return 0;
}