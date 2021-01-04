/*
문제 : 다이얼(https://www.acmicpc.net/problem/5622)
*/

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	string word;
	int sec = 0;
	cin >> word;
	for (int i = 0; i < word.size(); i++) {
		switch (word[i]) {
		case 'A': case 'B': case 'C':
			sec += 2;
			break;
		case 'D': case 'E': case 'F':
			sec += 3;
			break;
		case 'G': case 'H': case 'I':
			sec += 4;
			break;
		case 'J': case 'K': case 'L':
			sec += 5;
			break;
		case 'M': case 'N': case 'O':
			sec += 6;
			break;
		case 'P': case 'Q': case 'R': case 'S':
			sec += 7;
			break;
		case 'T': case 'U': case 'V':
			sec += 8;
			break;
		case 'W': case 'X': case 'Y': case 'Z':
			sec += 9;
			break;
		}
	}

	cout << sec + word.size() << endl;
	return 0;
}