/*
문제 : 정수 N개의 합 (https://www.acmicpc.net/problem/15596)
*/

#include <vector>

long long sum(std::vector<int>& a) {
	int sum = 0;
	for (int i = 0; i < a.size(); i++)
		sum += a[i];
	return sum;
}
