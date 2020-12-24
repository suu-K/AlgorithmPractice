/*
���� - �ִ� ���� �κ� ����(LIS)(https://algospot.com/judge/problem/read/LIS)
 � ���� �������� 0�� �̻��� ���ڸ� ����� �� ������ �κ� ���� (subsequence) �� ���� �� �ִ�.
 ���� ��� 10 7 4 9 �� �κ� �������� 7 4 9, 10 4, 10 9 ���� �ִ�. ��, 10 4 7 �� ���� ������ ������ �ٸ��Ƿ� 10 7 4 9 �� �κ� ������ �ƴϴ�.
 � �κ� ������ �������� �� �� �κ� ������ ���� �κ� ���� (increasing subsequence) ��� �Ѵ�.
 �־��� ������ ���� �κ� ���� �� ���� �� ���� ���̸� ����ϴ� ���α׷��� �ۼ��϶�.
 � ������ �� ���� ������ ������ Ŭ ��, �� ������ ������ �Ѵٰ� �Ѵ�.

�Է�
 �Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C (<= 50) �� �־�����.
 �� �׽�Ʈ ���̽��� ù �ٿ��� ������ ���Ե� ������ �� N (<= 500) �� �־�����.
 �� ���� �ٿ� ������ N���� ������ �־�����. �� ������ 1 �̻� 100,000 ������ �ڿ����̴�.

���
 �� �׽�Ʈ���̽����� �� �پ�, �־��� ������ ���� �� ���� �κ� ������ ���̸� ����Ѵ�.
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int cache[501];

int lis(int start) {
    int& ret = cache[start + 1];
    if (ret != -1) return ret;
    ret = 1;
    for (int i = start + 1; i < a.size(); i++) {
        if (start == -1 || a[start] < a[i])
            ret = max(ret, 1 + lis(i));
    }
    return ret;
}


void reset() {
    a.clear();
    for (int i = 0; i < 501; i++) {
        cache[i] = -1;
    }
    return;
}

int main() {
    int c;
    int n;
    int tmp;
    reset();
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            a.push_back(tmp);
        }
        cout << lis(-1) - 1 << endl;
        reset();
    }
    return 0;
}