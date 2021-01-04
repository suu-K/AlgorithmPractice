/*
문제 : X보다 작은 수(https://www.acmicpc.net/problem/10871)
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0, x = 0;
	int tmp;
	vector<int> arr;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < x)
			cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}