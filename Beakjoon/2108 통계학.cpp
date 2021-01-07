/*
문제 : 통계학(https://www.acmicpc.net/problem/2108)
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n = 0, tmp = 0;
	int mx = -4001, mn = 4001;	//최대, 최소
	int sum = 0, avg = 0, midx = 0, mode = 0;		//합계, 평균, 최빈값좌표, 최대 빈도
	int first = 0;
	vector<int> c(8001, 0);
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &tmp);
		sum += tmp;				//합계산 -> 평균
		c[tmp + 4000]++;
		mx = max(mx, tmp);		//최대 최소 계산 -> 범위
		mn = min(mn, tmp);
	}
	for (int i = 0; i < 8001; i++) {	//최빈값
		if (mode == c[i] && first) {
			midx = i - 4000;
			first = 0;
		}
		else if (mode < c[i]) {
			midx = i - 4000;
			mode = c[i];
			first = 1;
		}
	}
	for (int i = 0, idx = 0; i < 8001; i++) {	//카운팅정렬 -> 중앙값
		for (int j = 0; j < c[i]; j++) {
			v.push_back(i - 4000);
		}
	}
	avg = round((double)sum / n);

	cout << avg << endl;
	cout << v[n / 2] << endl;
	cout << midx << endl;
	cout << mx - mn << endl;
	return 0;
}
