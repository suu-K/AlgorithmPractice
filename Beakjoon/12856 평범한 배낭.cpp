/*
문제 : 평범한 배낭(https://www.acmicpc.net/problem/12865)

풀이
	유명한 knapsack 알고리즘 문제다.
	cache[i][j]를 i번째 보석까지 탐색하여 j의 무게를 채웠을 때 최대 가치라고 정의하면
	cache[i][j]는 두가지 경우가 있을 수 있다. i번쨰 물건을 획득할 때와 획득하지 않을 때.
	획득할 때는 i-1번쨰 물건까지 탐색해여 j - w[i]무게를 획득한 경우에 i번째 물건의 가치를 더한 값이고,
	획득하지 않을 때는 i-1번째 물건까지 j무게를 획득한 경우의 가치와 같다.
	따라서 다음 점화식이 성립한다.
	cache[i][j] = max(cache[i][j], cache[i - 1][j - w[i]] + v[i])
 */

#include <iostream>

using namespace std;

int w[101];		//물건의 무게
int v[101];		//물건의 가치
int cache[101][100001];	//i번째 물건까지 탐색하여 j만큼의 무게를 채웠을 때 획득 가능한 최대 가치

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			cache[i][j] = cache[i - 1][j];
			if (j >= w[i])	//i번쨰 물건의 무게가 현재 무게보다 크지 않다면
				cache[i][j] = max(cache[i][j], cache[i - 1][j - w[i]] + v[i]);
		}
	}

	cout << cache[n][k] << endl;
	return 0;
}