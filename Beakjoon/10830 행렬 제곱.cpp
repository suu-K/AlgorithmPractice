/*
문제 : 행렬 제곱(https://www.acmicpc.net/problem/10830)

코멘트
	문제를 시간안에 풀기 위해 분할 제곱을 이용하여 시간복잡도를 O(logN)으로 하였다.
	하지만 계속 오답이 나왔는데 처음 문제를 풀 때에는 행렬이 주어졌을때 b=1이면 주어진 행렬을 그대로 반환하게 하여 발생한 문제였다.
	그렇게 한다면 행렬의 구성 요소가 1000보다 크게 주어졌을때 답이 1000으로 나눈 나머지가 아니게 되므로 틀리게 된다.
 */

#include <iostream>
#include <vector>
#define MOD 1000

using namespace std;
typedef vector<vector<int>> matrix;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

matrix mul(matrix& a, matrix& b) {	//a행렬과 b행렬의 곱
	int y = a.size();
	int x = b[0].size();
	int n = b.size();
	matrix ret(y, vector<int>(x, 0));

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {

			for (int k = 0; k < n; k++) {
				ret[i][j] += (a[i][k] * b[k][j]);
			}
			ret[i][j] %= MOD;


		}
	}
	return ret;
}

matrix power(matrix& a, long long b) {	//a의 b제곱을 구하는 함수
	if (b == 1) {
		int n = a.size();		//모든 요소를 1000으로 나눈 나머지를 반환
		matrix ret = a;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				ret[y][x] %= MOD;
			}
		}
		return ret;
		/*
		* 단위행렬을 곱해서 1000의 나머지를 구하게 하는 방법
		int n = a.size();
		matrix unit(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
			unit[i][i] = 1;
		return mul(unit, a);
		*/
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
	int n, tmp;
	long long b;
	matrix a;
	cin >> n >> b;
	for (int y = 0; y < n; y++) {
		vector<int> v;
		for (int x = 0; x < n; x++) {
			cin >> tmp;
			v.push_back(tmp);
		}
		a.push_back(v);
	}

	printMatrix(power(a, b));

	return 0;
}