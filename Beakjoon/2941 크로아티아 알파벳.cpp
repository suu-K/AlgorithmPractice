/*
문제 : 크로아티아 알파벳(https://www.acmicpc.net/problem/2941)
 예전에는 운영체제에서 크로아티아 알파벳을 입력할 수가 없었다. 따라서, 다음과 같이 크로아티아 알파벳을 변경해서 입력했다.
 크로아티아 알파벳	변경
 ?					c=
 ?					c-
 d?					dz=
 đ					d-
 lj					lj
 nj					nj
 ?					s=
 ?					z=
 예를 들어, ljes=njak은 크로아티아 알파벳 6개(lj, e, ?, nj, a, k)로 이루어져 있다.
 단어가 주어졌을 때, 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.
 d?는 무조건 하나의 알파벳으로 쓰이고, d와 ?가 분리된 것으로 보지 않는다.
 lj와 nj도 마찬가지이다. 위 목록에 없는 알파벳은 한 글자씩 센다.

입력
 첫째 줄에 최대 100글자의 단어가 주어진다. 알파벳 소문자와 '-', '='로만 이루어져 있다.
 단어는 크로아티아 알파벳으로 이루어져 있다. 문제 설명의 표에 나와있는 알파벳은 변경된 형태로 입력된다.

출력
 입력으로 주어진 단어가 몇 개의 크로아티아 알파벳으로 이루어져 있는지 출력한다.
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