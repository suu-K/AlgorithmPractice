/*
문제 - 너드인가, 너드가 아닌가? 2(NERD2)(https://algospot.com/judge/problem/read/NERD2

풀이
	p와 q의 크기를 비교해야 하는데 이를 새로 입력될 때마다 전부 검사하면 자연스레 시간 복잡도는 O(N^2)이 되어버린다.
	그럼 이를 줄일 방법을 찾아야 하는데 만약 이미 p가 정렬되어 있다면 우리는 q의 크기만을 일부분만 비교하면 된다.
	다음 순서로 a, b의 순서쌍이 입력된다면 우리는 a가 이미 입력된 p들 사이에서 어디에 들어가야 하는지 찾고, 해당 위치에서 왼쪽에 있는 것만 비교하면 된다.
	이때 순서쌍을 입력받아 이를 이진 트리에 저장한다면 해당 값의 위치를 찾는데에 logN 만큼의 시간이 걸리므로 시간복잡도는 O(NlogN) 이 된다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>

using namespace std;

int main() {
	map<int, int> m;
	map<int, int>::iterator it;
	int c, n;
	int a, b;
	int sum;
	bool skip;
	cin >> c;
	for (int i = 0; i < c; i++) {
		m.clear();
		sum = 0;
		scanf("%d", &n);
		int num;
		for (int j = 0; j < n; j++) {
			scanf("%d%d", &a, &b);
			skip = false;
			it = m.lower_bound(a);	//해당 값이 들어갈 위치를 확인한다.
			if (it != m.end() && it->second > b) {	//그 위치의 바로 오른쪽과 비교하여 조건이 맞지 않으면 스킵
				skip = true;
			}
			else if (it != m.begin()) {		//해당 위치보다 왼쪽의 것들을 검사
				it--;
				while (it->second < b) {
					it = m.erase(it);

					if (it == m.begin())
						break;

					it--;
				}
			}
			if (!skip)
				m[a] = b;
			num = m.size();
			sum += num;	//현재 참가자 수를 더함
		}
		cout << sum << endl;
	}
	return 0;
}