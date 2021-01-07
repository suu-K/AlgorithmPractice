/*
문제 : 알람 시계(https://www.acmicpc.net/problem/2884)
*/

#include <iostream>

using namespace std;

int main()
{
	int h, m;
	int ah, am;
	cin >> h >> m;
	if (m >= 45) {
		am = m - 45;
		ah = h;
	}
	else if(h != 0){
		am = 60 - 45 + m;
		ah = h - 1;
	}
	else {
		am = 60 - 45 + m;
		ah = 23;
	}
	
	cout << ah << " " << am << endl;

	return 0;
}