/*
문제 - Microwaving Lunch Boxes(https://algospot.com/judge/problem/read/LUNCHBOX)

풀이
	만약 모든 도시락이 데우는 시간과 먹는 시간이 같다면 문제의 정답은 (모든 도시락을 데우는 시간)+(마지막 도시락을 먹는 시간)이 된다.
	그렇다면 모든 도시락을 먹는데 걸리는 최소 시간은 도시락을 먹는 시간이 긴 사람부터 도시락을 데우면 된다.
	이떄 마지막사람이 도시락을 데우고 먹는 데 두가지 경우가 생긴다.
		1. 마지막 도시락을 데우고 먹는 시간이 바로 전 사람이 도시락을 먹는 시간보다 길 경우
		2. 마지막 도시락을 데우고 먹는 시간이 바로 전 사람이 도시락을 먹는 시간보다 짧을 경우
	1의 경우엔 답은 (모든 도시락을 데우는 시간)+(마지막 도시락을 먹는 시간)이 된다.
	하지만 2의 경우에 마지막 사람이 도시락을 데우고 먹는데 걸리는 시간은 바로 전 사람이 도시락을 먹는 시간에 포함되므로 정답은 마지막 사람이 데우고 먹는 시간을 빼야 한다.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}


int main() {
	int c, n, m, e;
	int sumM;	//마지막 까지 먹는 사람이 데우는 데 걸리는 총 시간
	int restE;	//마지막까지 먹는 도시락 번호
	int curM;	//남은 도시락을 다 먹는데 시간


	cin >> c;
	for (int i = 0; i < c; i++) {
		sumM = 0;
		restE = 0;
		cin >> n;
		vector<pair<int, int>> v(n, pair<int, int>(0, 0));
		for (int i = 0; i < n; i++) {
			cin >> v[i].first;
			sumM += v[i].first;
		}
		for (int i = 0; i < n; i++) {
			cin >> v[i].second;
		}
		sort(v.begin(), v.end(), compare);
		restE = v.size() - 1;
		curM = v.back().first + v.back().second;		//맨 마지막 사람까지 먹는 사람이 도시락을 데우고 다 먹는 시간
		for (int i = v.size() - 2; i >= 0; i--) {
			if (curM < v[i].second) {					//뒤의 사람들이 도시락을 다 데우고 먹는 시간 보다 먹는 시간이 길 경우
				sumM -= curM - v[restE].second;			//현재 사람까지 도시락을 데우는 총 시간으로 바꿈
				restE = i;								//마지막까지 먹게되는 도시락은 현재 도시락
				curM = v[i].first + v[i].second;
			}
			else {
				curM += v[i].first;
			}
		}

		cout << sumM + v[restE].second << endl;
	}
	return 0;
}