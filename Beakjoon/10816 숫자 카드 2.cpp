/*
문제 : 숫자 카드 2(https://www.acmicpc.net/problem/10816)

코멘트
	이진트리로 하니 입력시간 때문인지 시간 초과가 난다.
	따라서 배열에 저장하고 따로 이진탐색을 써야 한다.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {
	init();
	int n, m, tmp;

	cin >> n;
	vector<int> v1(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v1[i];
	}

	sort(v1.begin(), v1.end());

	cin >> m;
	vector<int> v2(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> v2[i];
	}

	for (int i = 0; i < m; i++) {
		cout << upper_bound(v1.begin(), v1.end(), v2[i]) - lower_bound(v1.begin(), v1.end(), v2[i]) << " ";
	}
	cout << "\n";


	return 0;
}