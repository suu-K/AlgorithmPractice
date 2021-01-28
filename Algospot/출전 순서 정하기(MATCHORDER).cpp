/*
문제 - 출전 순서 정하기(https://algospot.com/judge/problem/read/MATCHORDER)

풀이
	러시아 선수의 점수가 한국의 모든 선수의 점수보다 높다면 가장 점수가 낮은 사람을 매칭시키고
	그 이외에는 해당 러시아 선수와 점수가 가장 근접한 이길 수 있는 사람을 매칭시킨다.
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main() {
	int c, n, tmp;
	vector<int> russia, korea;
	cin >> c;
	for (int i = 0; i < c; i++) {
		russia.clear();
		korea.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			russia.push_back(tmp);
		}
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			korea.push_back(tmp);
		}
		int ret = 0;
		multiset<int> order(korea.begin(), korea.end());
		for (int i = 0; i < n; i++) {
			if (russia[i] > * order.rbegin()) {
				order.erase(order.begin());
			}
			else {
				order.erase(order.lower_bound(russia[i]));
				ret++;
			}
		}
		cout << ret << endl;
	}
	return 0;
}