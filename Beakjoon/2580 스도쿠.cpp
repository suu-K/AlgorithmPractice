/*
���� : ������(https://www.acmicpc.net/problem/2580)

Ǯ��
	��Ʈ��ŷ�� �̿��� ����Ž������ �˰����� ¥�� ���� �������� �ڲ� ������ ������.
	�� ������ ������ �ϳ��� ����ؾ� �ϴ� ���� Ư�� �� ����Լ��� ������ ������ ���� ���� ��ġ�� �Ǿ���� �ٴ� ���̴�.
	���� ���ʿ� ���� ã������ �� ��� ������ ����ϰ� ���α׷��� �����ϵ��� �ؾ� �ߴ�.
 */

#include <iostream>
#include <vector>

using namespace std;

struct point {	//��ǥ
	int x;
	int y;
	point(int x, int y) : x(x), y(y) {};
}typedef point;

int b[9][9];		//������ ��
vector<point> v;	//��ĭ�� ��ǥ ����� ����

void printB() {		//������ �� ���
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cout << b[y][x] << " ";
		}
		cout << endl;
	}
}

bool check(int y, int x, int n) {	//��ġ�� ���ڰ� �ִ��� ����
	for (int i = 0; i < 9; i++) {	//���� ���ο� ��ġ�� ���ڰ� �ִ��� �˻�
		if (b[y][i] == n)
			return false;
		if (b[i][x] == n)
			return false;
	}
	int nx = (x / 3) * 3;
	int ny = (y / 3) * 3;
	for (int i = ny; i < ny + 3; i++)	//�簢�� �ȿ� ��ġ�� ���ڰ� �ִ��� �˻�
		for (int j = nx; j < nx + 3; j++)
			if (b[i][j] == n)
				return false;
	return true;
}

void solve(int idx) {
	if (idx == v.size()) {	//���� ��ĭ�� �� ä������ ����� ���α׷� ����
		printB();
		exit(0);
	}
	for (int i = 1; i <= 9; i++) {	//��ĭ�� 1���� 9���� �ϳ��� �־�� �˻�
		if (check(v[idx].y, v[idx].x, i)) {	//���� ��ġ�� ���ڰ� ������ �ְ�
			b[v[idx].y][v[idx].x] = i;
			solve(idx + 1);					//���� ��ĭ�� ä���
		}
	}
	b[v[idx].y][v[idx].x] = 0;		//���� �´� ���� ���ٸ� ��ĭ���� �ǵ�����.
	return;
}



int main() {
	int tmp;
	int cnt = 0;
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cin >> tmp;
			if (tmp == 0)
				v.push_back(point(x, y));
			b[y][x] = tmp;
		}
	}
	solve(0);
	return 0;
}
