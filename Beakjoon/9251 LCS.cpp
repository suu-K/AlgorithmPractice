/*
문제 : LCS(https://www.acmicpc.net/problem/9251)
 */

#include <iostream>

using namespace std;

string a, b;
int cache[1000][1000];

int lcs(int aidx, int bidx) {		//a문자열의 aidx부터, b문자열의 bidx부터 비교하는 함수
	if (aidx >= a.size() || bidx >= b.size())	//둘 중 하나가 끝에 도달했다면 더이상 같은 것은 없음
		return 0;

	int& ret = cache[aidx][bidx];
	if (ret != -1)
		return ret;

	ret = 0;
	if (a[aidx] == b[bidx])		//현재 문자가 같다면 개수를 1 증가시키고 나머지 호출
		return ret = 1 + lcs(aidx + 1, bidx + 1);

	ret = max(lcs(aidx + 1, bidx), lcs(aidx, bidx + 1));	//같은게 없다면 a,b의 다음 문자를 비교
	return ret;
}

void reset() {
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			cache[i][j] = -1;
}

int main() {
	cin >> a >> b;
	reset();
	cout << lcs(0, 0) << endl;
	return 0;
}