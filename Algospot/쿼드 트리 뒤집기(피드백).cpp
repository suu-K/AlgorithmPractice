/*
�ǵ�� - ���� Ʈ�� ������(QUADTREE)(https://algospot.com/judge/problem/read/QUADTREE)
 å�� ���信���� iterator�� �̿��� �� �� ����ϰ� ������ Ǯ���־���.
 ó���� ������ Ǯ���� �� ���� ��ٷο��� �κ��� ���� ���ڿ��� ��� �Ѿ�°� ����.
 ���� ��쿡�� ��ȯ�� ���ڿ��� ���̸� �̿������� ��ó�� iterator�� �̿��� ��ĭ�� ������Ű�� �ξ� �ڵ尡 ���������.
*/
#include <iostream>
#include <vector>

using namespace std;

string reverse(string::iterator& it) {
    char head = *it;
    string part[4];
    ++it;
    if (head == 'w' || head == 'b')
        return string(1, head);
    part[0] = reverse(it);
    part[1] = reverse(it);
    part[2] = reverse(it);
    part[3] = reverse(it);
    return "x" + part[2] + part[3] + part[0] + part[1];
}

int main() {
    int c;
    string picture;
    string::iterator it;
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> picture;
        it = picture.begin();
        cout << reverse(it) << endl;
        picture.clear();
    }

    return 0;
}