/*
문제 : 하노이 탑 이동 순서(https://www.acmicpc.net/problem/11729)
 */

#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int a, int b, int c, int n) {	//n개의 원판을 a막대에서 c막대로 옮기는 함수
	if (n == 1) {
		printf("\n%d %d", a, c);
		return;
	}

	hanoi(a, c, b, n - 1);	//a에서 b로 n-1개를 옮긴다.
	printf("\n%d %d", a, c);		//a에서 c로 1개를 옮긴다.
	hanoi(b, a, c, n - 1);	//b에서 c로 n-1개를 옮긴다.
	return;
}


int main() {
	int n = 0;
	cin >> n;
	cout << (int)pow(2, n) - 1;
	hanoi(1, 2, 3, n);
	return 0;
}