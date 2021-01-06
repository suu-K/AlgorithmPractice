/*
문제 : 전깃줄(https://www.acmicpc.net/problem/2565)

풀이
	전깃줄을 전봇대 a의 1번 위치부터 차례대로 보자면 결국 이전보다 큰 수가 연결되어 있어야 한다.
	이는 전봇대 b의 증가 부분 수열과 같다. 따라서 전깃줄을 최소로 없애기 위해선 가장 긴 증가 부분 수열을 찾으면 된다.
	하지만 처음에 전깃줄이 주어질 때 순서대로 주어지지 않으므로 전봇대 a를 기준으로 정렬 한 뒤 전보대 b의 최대 증가 부분 수열을 찾는다.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pole {
	int a;
	int b;
	pole(int a, int b) : a(a), b(b) {};
}typedef pole;

int a[101];		//수열을 저장하는 배열
int cache[101];	//부분 증가수열 메모이제이션 용 배열
int n;				//주어진 수열의 길이

int lis(int idx) {	//최댓값 까지의 부분 증가 수열
	if (idx > n)
		return 0;

	int& ret = cache[idx];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int next = idx + 1; next <= n; next++) {
		if (a[next] > a[idx])
			ret = max(ret, lis(next) + 1);
	}

	return ret;
}

void reset() {
	for (int i = 0; i < 101; i++)
		cache[i] = -1;
}

bool inc(pole a, pole b) {	//a전봇대의 순서대로 정렬
	if (a.a < b.a)
		return true;
	else
		return false;
}


int main() {
	int an, bn;
	vector<pole> v;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> an >> bn;
		v.push_back(pole(an, bn));
	}
	reset();

	sort(v.begin(), v.end(), inc);

	a[0] = 0;						//정렬된 수열을 옮김
	for (int i = 1; i <= n; i++) {
		a[i] = v[i - 1].b;
	}


	cout << n - lis(0) << endl;		//전깃줄의 전체 개수에서 최대 증가 부분 수열을 빼면 없애야 할 전깃줄의 수

	return 0;
}