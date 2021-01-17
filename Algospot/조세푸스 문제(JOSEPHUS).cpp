/*
문제 -조세푸스 문제(JOSEPHUS)(https://algospot.com/judge/problem/read/JOSEPHUS)

풀이
	1부터 n까지 차례대로 리스트에 입력한 뒤 둘이 남을 때까지 죽는 순서대로 차례차례 리스트에서 지워간다.
	동적배열은 중간의 인자를 제거하면 추가적인 연산이 많이 필요하므로 리스트를 이용했다.
*/


#include <iostream>
#include <list>

using namespace std;

int main() {
	int c;
	int n, k;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n >> k;
		list<int> lt;
		for (int i = 1; i <= n; i++)
			lt.push_back(i);

		list<int>::iterator kill = lt.begin();

		while (n > 2) {
			kill = lt.erase(kill);
			if (kill == lt.end())
				kill = lt.begin();

			n--;
			for (int i = 0; i < k - 1; i++) {
				kill++;
				if (kill == lt.end())
					kill = lt.begin();
			}
		}

		cout << lt.front() << " " << lt.back() << endl;
	}

	return 0;
}