/*
�ǵ�� - ��Ÿ�� �߶󳻱�(FENCE)(https://algospot.com/judge/problem/read/FENCE)
 ó���� ������ Ǯ ������ ����Ž���� ����� �˰����� �̿������� �̷� ��� n*n�� ����� �ð����⵵�� ���´�.
 ��� ���� ������ �� �����Ͽ� ������ �޾Ƴ� �� �־����� ��ȿ�������� ���� �� �ִٴ� ���� �˰��ִ�.

 �� ������ Ǫ�� �ٸ� ����� ���� ������ �̿��ϴ� Ǯ���̴�.
 ����� �������� �䱸�ϴ� ������ ���� ū ���ڴ� 3���� ��쿡�� ���� �� �ִ�.
 1. ���� ���ڵ� �ȿ� �ִ�.
 2. ������ ���ڵ� �ȿ� �ִ�.
 3. ���ʿ� ������ �ִ�.
 1,2���� ���� ������ ��� ȣ���� �̿��ϰ� 3���� ����������� �¿�� Ȯ���ذ��� Ž���Ѵ�.
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> h;

int maxSize(int left, int right) {  //������ �¿� ������ ��ȯ
    int ret = 0;
    if (left == right) return h[left];  //���ڰ� �ϳ��ۿ� ���� ���
    int mid = (right + left) / 2;
    ret = max(maxSize(left, mid), maxSize(mid + 1, right)); //�¿�� ����

    //��� ��ģ ���� �� ���� ū �� ã��
    int l = mid, r = mid + 1;   //��� �¿� 2ĭ
    int height = min(h[l], h[r]);
    ret = max(ret, height * (r - l + 1)); //���� �ʺ� 2�� ������ ����
    while (left < l || r < right) {
        if (left < l && (r == right || h[l - 1] > h[r + 1]))  //���� ���� ���ڰ� ������ ���� ���ں��� Ŭ��
            height = min(height, h[--l]);   //�������� ��ĭ Ȯ��
        else
            height = min(height, h[++r]);   //���������� ��ĭ Ȯ��
        ret = max(ret, height * (r - l + 1));
    }
    return ret;
}

int main() {
    int c;
    int n, tmp;
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            h.push_back(tmp);
        }
        cout << maxSize(0, h.size() - 1) << endl;
        h.clear();
    }
    return 0;
}