/*
문제 : 단어의 개수(https://www.acmicpc.net/problem/1152)
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	int count = 0;
	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ')
			count++;
	}
	if (str[0] == ' ')
		count--;
	if (str.back() == ' ')
		count--;
	cout << count + 1 << endl;
	return 0;
}