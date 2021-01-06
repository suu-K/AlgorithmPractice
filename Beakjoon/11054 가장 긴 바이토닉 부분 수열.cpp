/*
���� : ���� �� ������� �κ� ����(https://www.acmicpc.net/problem/11054)
 */

#include <iostream>

using namespace std;

int a[1001];		//������ �����ϴ� �迭
int cacheI[1001];	//�κ� �������� �޸������̼� �� �迭
int cacheD[1001];	//�κ� ���Ҽ��� �޸������̼� �� �迭
int n;				//�־��� ������ ����
int mxIdx;			//������� �κ� ������ �߽��� �Ǵ� �ִ�

void reset() {		//ĳ�� �ʱ�ȭ
	for (int i = 0; i < 1001; i++) {
		cacheI[i] = -1;
		cacheD[i] = -1;
	}
}
void resetI() {		//ĳ�� �ʱ�ȭ
	for (int i = 0; i < 1001; i++) {
		cacheI[i] = -1;
	}
}


int lis(int idx) {	//�ִ� ������ �κ� ���� ����
	if (idx > mxIdx)
		return 0;

	int& ret = cacheI[idx];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int next = idx + 1; next <= mxIdx; next++) {
		if (a[next] > a[idx])
			ret = max(ret, lis(next) + 1);
	}

	return ret;
}
int lds(int idx) {	//�ִ� ������ �κ� ���� ����
	if (idx > n)
		return 0;

	int& ret = cacheD[idx];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int next = idx + 1; next <= n; next++) {
		if (a[next] < a[idx])
			ret = max(ret, lds(next) + 1);
	}

	return ret;
}

int lbs() {	//�ִ��� �߽����� �κ� ���������� �κ� ���Ҽ����� ���� ���� �˻�
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		resetI();	//�κ� ���� ������ ������ �޶����Ƿ� ��� �Ҷ����� �ʱ�ȭ
		mxIdx = i;
		ret = max(ret, lis(0) + lds(mxIdx));
	}
	return ret;
}

int main() {
	cin >> n;
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	reset();

	cout << lbs() << endl;

	return 0;
}