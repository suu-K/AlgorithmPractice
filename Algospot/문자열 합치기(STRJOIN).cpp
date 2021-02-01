/*
문제 - 문자열 합치기(https://algospot.com/judge/problem/read/STRJOIN)

풀이
	가장 적은 비용이 될려면 매 순간마다 가장 길이가 짧은 문자열 두 개를 합치는 것이다.
	이를 위해 주어진 문자열들을 길이 순으로 정렬하여 가장 짧은 두 문자열을 합친뒤 이를 반복하였다.
*/

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int count(multiset<int>& s) {
	int ret = 0;
	int tmp = 0;
	while (s.size() != 1) {
		tmp = 0;
		tmp += *s.begin(); s.erase(s.begin());	//맨 앞의 숫자 2개를 더한 뒤 제거
		tmp += *s.begin(); s.erase(s.begin());
		ret += tmp;
		s.insert(tmp);	//합친 숫자를 다시 삽입
	}
	return ret;
}


int main() {
	int c, n, tmp;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		multiset<int> s;		//문자열들이 항상 길이순으로 정렬되게 이진트리에 저장
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			s.insert(tmp);
		}

		cout << count(s) << endl;

	}
	return 0;
}