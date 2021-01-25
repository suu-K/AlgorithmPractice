/*
문제 - 여행 짐 싸기(https://algospot.com/judge/problem/read/PACKING)

풀이
	유명한 knapsack 알고리즘 문제이다. 가장 기본적인 문제이면서 이후에 해당 답의 목록을 추적해야하는 부분이 추가되었다.
	답을 추적하는 방법은 재귀적으로 짜여져 있는 최적해를 찾는 알고리즘을 마찬가지로 재귀적으로 역순으로 행하면서 답을 넣으면 된다.
*/

#include <iostream>
#include <vector>

using namespace std;

int cache[1001][101];		//메모이제이션용 배열
string name[101];			//이름
int vol[101];				//부피
int need[101];				//절박도
vector<int> v;				//담을 물건 목록


int pack(int cap, int item) {		//절박도의 최대치를 반환하는 함수
	if (item == 0)		//담을 물건이 없다면 반환
		return 0;

	int& ret = cache[cap][item];
	if (ret != -1)
		return ret;

	ret = pack(cap, item - 1);	//item번쨰 물건을 담지 않을 때
	if (cap >= vol[item]) {		//item번쨰 물건을 담을 때
		ret = max(ret, pack(cap - vol[item], item - 1) + need[item]);	//담을 때와 담지 않을때의 최대값 비교
	}

	return ret;
}

void find(int cap, int item, vector<int>& v) {	//v에 담을 물건의 목록을 저장하는 함수
	if (item <= 0)
		return;

	if (pack(cap, item) == pack(cap, item - 1))	//item번째 물건을 담지 않은 경우
		find(cap, item - 1, v);
	else if (pack(cap, item) == pack(cap - vol[item], item - 1) + need[item]) {	//item번째 물건을 담은 경우
		v.push_back(item);
		find(cap - vol[item], item - 1, v);
	}
	return;
}



void reset() {
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 101; j++) {
			cache[i][j] = -1;
			vol[j] = -1;
			need[j] = -1;

		}
	}
	name->clear();
	v.clear();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;
	int n, w;
	cin >> c;
	for (int i = 0; i < c; i++) {
		reset();
		cin >> n >> w;
		for (int j = 1; j <= n; j++) {
			cin >> name[j] >> vol[j] >> need[j];
		}

		int need = pack(w, n);
		find(w, n, v);
		cout << need << " " << v.size() << endl;
		for (int j = v.size() - 1; j >= 0; j--)
			cout << name[v[j]] << endl;
	}

	return 0;
}