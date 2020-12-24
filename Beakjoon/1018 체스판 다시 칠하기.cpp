/*
문제 : 체스판 다시 칠하기(https://www.acmicpc.net/problem/1018)
 지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M*N 크기의 보드를 찾았다.\
 어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 지민이는 이 보드를 잘라서 8*8 크기의 체스판으로 만들려고 한다.
 체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다.
 따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.
 보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8*8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다.
 당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.

입력
 첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다.
 둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.

출력
 첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.
 */

#include <iostream>

using namespace std;

int board[50][50];

int check(int y, int x) {
	int start = board[y][x];
	int before = !start;
	int count1 = 0, count2 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (before == board[y + i][x + j])
				count1++;
			before = !before;
		}
		before = !before;
	}
	before = start;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (before == board[y + i][x + j])
				count2++;
			before = !before;
		}
		before = !before;
	}
	return min(count1, count2);
}

int main() {
	int n = 0, m = 0;
	string s;
	int count = 65;
	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		cin >> s;
		for (int x = 0; x < m; x++) {
			if (s[x] == 'W')
				board[y][x] = 1;
			else
				board[y][x] = 0;
		}
	}
	for (int y = 0; y <= n - 8; y++) {
		for (int x = 0; x <= m - 8; x++) {
			count = min(count, check(y, x));
		}
	}
	cout << count << endl;
	return 0;
}
