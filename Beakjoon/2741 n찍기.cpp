﻿/*
문제 : n찍기(https://www.acmicpc.net/problem/2741)
*/

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cout << i << "\n";
	return 0;
}