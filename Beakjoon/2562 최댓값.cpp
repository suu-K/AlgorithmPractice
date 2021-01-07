/*
문제 : 최댓값 (https://www.acmicpc.net/problem/2562)
*/

#include <iostream>

using namespace std;

int main() {
	int maximum = 0, idx = 0;
	int tmp;
	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		maximum = max(maximum, tmp);
		if (tmp == maximum)
			idx = i + 1;
	}

	cout << maximum << endl << idx << endl;


	return 0;
}