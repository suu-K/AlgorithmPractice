﻿/*
문제 : 스도쿠(https://www.acmicpc.net/problem/2580)

풀이
	백트랙킹을 이용한 완전탐색으로 알고리즘을 짜는 것은 쉬웠으나 자꾸 오답이 났었다.
	그 이유는 정답을 하나만 출력해야 하는 문제 특성 상 재귀함수를 끝까지 돌리면 여러 답을 거치게 되어버린 다는 것이다.
	따라서 최초에 답을 찾았으면 그 즉시 정답을 출력하고 프로그램을 종료하도록 해야 했다.
 */

#include <iostream>
#include <vector>

using namespace std;

struct point {	//좌표
	int x;
	int y;
	point(int x, int y) : x(x), y(y) {};
}typedef point;

int b[9][9];		//스도쿠 판
vector<point> v;	//빈칸의 좌표 저장용 벡터

void printB() {		//스도쿠 판 출력
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cout << b[y][x] << " ";
		}
		cout << endl;
	}
}

bool check(int y, int x, int n) {	//겹치는 숫자가 있는지 조사
	for (int i = 0; i < 9; i++) {	//가로 세로에 겹치는 숫자가 있는지 검사
		if (b[y][i] == n)
			return false;
		if (b[i][x] == n)
			return false;
	}
	int nx = (x / 3) * 3;
	int ny = (y / 3) * 3;
	for (int i = ny; i < ny + 3; i++)	//사각형 안에 겹치는 숫자가 있는지 검사
		for (int j = nx; j < nx + 3; j++)
			if (b[i][j] == n)
				return false;
	return true;
}

void solve(int idx) {
	if (idx == v.size()) {	//만일 빈칸을 다 채웠으면 출력후 프로그램 종료
		printB();
		exit(0);
	}
	for (int i = 1; i <= 9; i++) {	//빈칸에 1부터 9까지 하나씩 넣어가며 검사
		if (check(v[idx].y, v[idx].x, i)) {	//만일 겹치는 숫자가 없으면 넣고
			b[v[idx].y][v[idx].x] = i;
			solve(idx + 1);					//다음 빈칸을 채운다
		}
	}
	b[v[idx].y][v[idx].x] = 0;		//만일 맞는 수가 없다면 빈칸으로 되돌린다.
	return;
}



int main() {
	int tmp;
	int cnt = 0;
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> tmp;
			if (tmp == 0)
				v.push_back(point(x, y));
			b[y][x] = tmp;
		}
	}
	solve(0);
	return 0;
}
