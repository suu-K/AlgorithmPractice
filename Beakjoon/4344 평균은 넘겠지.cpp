/*
문제 : 평균은 넘겠지 (https://www.acmicpc.net/problem/4344)
*/

#include <iostream>
#include <vector>

using namespace std;

double rate(vector<int> score) {
	double ret = 0;
	double avg = 0;
	int stu = 0, sum = 0;

	for (int i = 0; i < score.size(); i++) {
		sum += score[i];
	}
	avg = (double)sum / score.size();
	for (int i = 0; i < score.size(); i++)
		if (score[i] > avg)
			stu++;
	ret = (double)stu / score.size() * 100;
	return ret;
}

int main() {
	int c = 0;
	int n = 0;
	int tmp = 0;
	vector<int> score;
	cout << fixed;
	cout.precision(3);
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			score.push_back(tmp);
		}
		cout << rate(score) << "%" << endl;
		n = 0, tmp = 0;
		score.clear();
	}

	return 0;
}