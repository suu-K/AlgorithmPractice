/*
문제 : 가장 긴 바이토닉 부분 수열(https://www.acmicpc.net/problem/11054)
 */

#include <iostream>

using namespace std;

int a[1001];		//수열을 저장하는 배열
int cacheI[1001];	//부분 증가수열 메모이제이션 용 배열
int cacheD[1001];	//부분 감소수열 메모이제이션 용 배열
int n;				//주어진 수열의 길이
int mxIdx;			//바이토닉 부분 수열의 중심이 되는 최댓값

void reset() {		//캐시 초기화
	for (int i = 0; i < 1001; i++) {
		cacheI[i] = -1;
		cacheD[i] = -1;
	}
}
void resetI() {		//캐시 초기화
	for (int i = 0; i < 1001; i++) {
		cacheI[i] = -1;
	}
}


int lis(int idx) {	//최댓값 까지의 부분 증가 수열
	if (idx > mxIdx)
		return 0;

	int& ret = cacheI[idx];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int next = idx + 1; next <= mxIdx; next++) {
		if (a[next] > a[idx])
			ret = max(ret, lis(next) + 1);
	}

	return ret;
}
int lds(int idx) {	//최댓값 부터의 부분 감소 수열
	if (idx > n)
		return 0;

	int& ret = cacheD[idx];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int next = idx + 1; next <= n; next++) {
		if (a[next] < a[idx])
			ret = max(ret, lds(next) + 1);
	}

	return ret;
}

int lbs() {	//최댓값을 중심으로 부분 증가수열과 부분 감소수열의 합을 전부 검사
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		resetI();	//부분 증가 수열의 범위가 달라지므로 계산 할때마다 초기화
		mxIdx = i;
		ret = max(ret, lis(0) + lds(mxIdx));
	}
	return ret;
}

int main() {
	cin >> n;
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	reset();

	cout << lbs() << endl;

	return 0;
}