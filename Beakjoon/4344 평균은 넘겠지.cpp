/*
문제 : 평균은 넘겠지 (https://www.acmicpc.net/problem/4344)
 대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.

입력
 첫째 줄에는 테스트 케이스의 개수 C가 주어진다.
 둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다.
 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

출력
 각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.
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