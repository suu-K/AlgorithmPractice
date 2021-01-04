/*
문제 : 크로아티아 알파벳(https://www.acmicpc.net/problem/2941)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string word;
	int num = 0;
	cin >> word;
	for (int i = 0; i < word.size(); i++) {
		switch (word[i]) {
		case 'c':
			if (word[i + 1] == '=' || word[i + 1] == '-')
				i++;
			num++; break;
		case 'd':
			if (word[i + 1] == '-')
				i++;
			else if (word[i + 1] == 'z' && word[i + 2] == '=')
				i += 2;
			num++; break;
		case 'l': case 'n':
			if (word[i + 1] == 'j')
				i++;
			num++; break;
		case 's': case 'z':
			if (word[i + 1] == '=')
				i++;
			num++; break;
		default:
			num++;
		}
	}
	cout << num << endl;
	return 0;
}