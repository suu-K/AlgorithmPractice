/*
���� : �ð� ���߱�(CLOCKSYNC)(https://algospot.com/judge/problem/read/CLOCKSYNC)
 16���� �ð谡 ��� 12��, 3��, 6��, 9�� �� �ϳ��� ����Ű�� �ִ�.
 ���� �ϳ� �̻��� �ð�� ����� 10���� ����ġ�� �ְ� �� ����ġ�� ������ ����� �ð谡 3�ð��� ������ �����δ�.
 �� �ð��� ���� �ð��� �־����� ����ġ�� ������ ��� 12�ø� ����Ű�� �ϴ� �ּ� Ƚ���� ���϶�.

�Է�
 ù �ٿ��� �׽�Ʈ ���̽� C�� ���� �־�����.
 �� �׽�Ʈ ���̽��� �� �ٿ� 16���� ������ �־�����, �� ������ 0������ 15������ �� �ð谡 ����Ű�� �ִ� �ð��� 12, 3, 6, 9 �� �ϳ��� ǥ���Ѵ�.

���
 �� �׽�Ʈ ���̽��� ���� �ϳ��� ���ٿ� ����մϴ�.
 �� ������ �ð���� ��� 12�÷� �������� ���� ����ġ�� ������ �� �ּ� Ƚ������ �ϸ�, ���� �̰��� �Ұ����� ��� -1�� ����ؾ� �մϴ�.
 */

 /*
 Ǯ��
  ����Լ��� �̿��� ����Ž������ ��� ����� ���� ���캻��.
  �� ����ġ�� 4�� ������ ���ڸ��̹Ƿ� �� ����ġ�� ���� �ִ��� ������ 3���̴�.
  16���� �ð踦 0-3���� ������ ����� ���� ��� ����.
 */

#include <iostream>
#include <vector>

using namespace std;

int TimesOfPush(vector<int>& clock, int curSwitch); //����ġ�� ������ �ּ� Ƚ���� ���ϴ� �Լ�, curSwitch�� ���� ������ �ϴ� ����ġ
void PushSwitch(vector<int>& clock, int curSwitch); //���� ����ġ�� �� �� ���� clock�� �ð踦 �����̴� �Լ�
bool CheckClock(vector<int>& clock);    //�ð谡 ��� 12�ø� ����Ű���� Ȯ���ϴ� �Լ�

const int INF = 9999999;    //����ġ�� �ִ�� ������ 3^10���� ū, ���� �� ���� ��. ���� ���

vector<vector<int>> link = {    //link[i][] i�� ����ġ�� ����� �ð��
    {0,1,2},
    {3,7,9,11},
    {4,10,14,15},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15},
    {3,14,15},
    {4,5,7,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}
};

int main()
{
    int c = 0; //�׽�Ʈ ���̽�
    int num = 0;
    vector<int> clock;  //�ð��� ����
    cin >> c;
    for (int t = 0; t < c; t++) {
        int tmp;
        for (int j = 0; j < 16; j++) {
            cin >> tmp;
            clock.push_back(tmp);
        }
        num = TimesOfPush(clock, 0);

        if (num == INF) //�ð踦 ��� ������ �� �ִ� ��찡 ���� ���
            cout << -1 << endl;
        else
            cout << num << endl;

        clock.clear();
        num = 0;
        tmp = 0;
    }
    return 0;
}

int TimesOfPush(vector<int>& clock, int curSwitch) {
    int times = INF;
    if (curSwitch == 10)    //10�� ����ġ�� ��� ������ ��
        if (CheckClock(clock))
            return 0;
        else                //�ð谡 ���ĵ��� �ʾ����� ���� ��ȯ
            return INF;

    for (int i = 0; i < 4; i++) {
        PushSwitch(clock, curSwitch);   //����ġ�� �� �� ����
        int rest = TimesOfPush(clock, curSwitch + 1);   //������ ����ġ�� ���� �ð踦 ������ Ƚ��
        if (i != 3) //���� ����ġ�� ���� Ƚ���� ����
            rest += i + 1;
        times = min(times, rest);   //����� ���� ���ٸ� ����, �ִٸ� �ּҰ��� ����
    }   //����ġ�� �� 4�� ������ �ٽ� ���� ���°� �ǹǷ� 0�� ���� �Ͱ� ����.
    return times;
}

void PushSwitch(vector<int>& clock, int curSwitch) {
    for (int i = 0; i < link[curSwitch].size(); i++) {
        clock[link[curSwitch][i]] += 3;
        if (clock[link[curSwitch][i]] == 15)    //12�ø� �Ѱܼ� �ٽ� 0�ú��� ���� ���
            clock[link[curSwitch][i]] = 3;
    }
}

bool CheckClock(vector<int>& clock) {
    bool checker = true;
    for (int i = 0; i < clock.size(); i++) {
        if (clock[i] != 12) {   //�ϳ��� 12�ð� �ƴ� �ð谡 �ִٸ� false
            checker = false;
            break;
        }
    }
    return checker;
}