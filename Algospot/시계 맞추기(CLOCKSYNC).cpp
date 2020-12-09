/*
문제 : 시계 맞추기(CLOCKSYNC)(https://algospot.com/judge/problem/read/CLOCKSYNC)
 16개의 시계가 모두 12시, 3시, 6시, 9시 중 하나를 가리키고 있다.
 각각 하나 이상의 시계와 연결된 10개의 스위치가 있고 이 스위치를 누르면 연결된 시계가 3시간씩 앞으로 움직인다.
 각 시계의 현재 시간이 주어지면 스위치를 눌러서 모두 12시를 가리키게 하는 최소 횟수를 구하라.

입력
 첫 줄에는 테스트 케이스 C의 수가 주어진다.
 각 테스트 케이스는 한 줄에 16개의 정수로 주어지며, 각 정수는 0번부터 15번까지 각 시계가 가리키고 있는 시간을 12, 3, 6, 9 중 하나로 표현한다.

출력
 각 테스트 케이스당 정수 하나를 한줄에 출력합니다.
 이 정수는 시계들을 모두 12시로 돌려놓기 위해 스위치를 눌러야 할 최소 횟수여야 하며, 만약 이것이 불가능할 경우 -1을 출력해야 합니다.
 */

 /*
 풀이
  재귀함수를 이용한 완전탐색으로 모든 경우의 수를 살펴본다.
  각 스위치를 4번 누르면 제자리이므로 각 스위치를 누를 최대의 개수는 3번이다.
  16개의 시계를 0-3번씩 누르는 경우의 수를 모두 센다.
 */

#include <iostream>
#include <vector>

using namespace std;

int TimesOfPush(vector<int>& clock, int curSwitch); //스위치를 누르는 최소 횟수를 구하는 함수, curSwitch는 현재 눌러야 하는 스위치
void PushSwitch(vector<int>& clock, int curSwitch); //현재 스위치를 한 번 눌러 clock의 시계를 움직이는 함수
bool CheckClock(vector<int>& clock);    //시계가 모두 12시를 가리키는지 확인하는 함수

const int INF = 9999999;    //스위치를 최대로 누르는 3^10보다 큰, 나올 수 없는 수. 무한 취급

vector<vector<int>> link = {    //link[i][] i번 스위치와 연결된 시계들
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
    int c = 0; //테스트 케이스
    int num = 0;
    vector<int> clock;  //시계의 상태
    cin >> c;
    for (int t = 0; t < c; t++) {
        int tmp;
        for (int j = 0; j < 16; j++) {
            cin >> tmp;
            clock.push_back(tmp);
        }
        num = TimesOfPush(clock, 0);

        if (num == INF) //시계를 모두 정렬할 수 있는 경우가 없는 경우
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
    if (curSwitch == 10)    //10개 스위치를 모두 눌렀을 떄
        if (CheckClock(clock))
            return 0;
        else                //시계가 정렬되지 않았으면 무한 반환
            return INF;

    for (int i = 0; i < 4; i++) {
        PushSwitch(clock, curSwitch);   //스위치를 한 번 누름
        int rest = TimesOfPush(clock, curSwitch + 1);   //나머지 스위치를 눌러 시계를 정렬한 횟수
        if (i != 3) //현재 스위치를 누른 횟수를 더함
            rest += i + 1;
        times = min(times, rest);   //경우의 수가 없다면 무한, 있다면 최소값을 저장
    }   //스위치를 총 4번 누르면 다시 원래 상태가 되므로 0번 누른 것과 같음.
    return times;
}

void PushSwitch(vector<int>& clock, int curSwitch) {
    for (int i = 0; i < link[curSwitch].size(); i++) {
        clock[link[curSwitch][i]] += 3;
        if (clock[link[curSwitch][i]] == 15)    //12시를 넘겨서 다시 0시부터 셌을 경우
            clock[link[curSwitch][i]] = 3;
    }
}

bool CheckClock(vector<int>& clock) {
    bool checker = true;
    for (int i = 0; i < clock.size(); i++) {
        if (clock[i] != 12) {   //하나라도 12시가 아닌 시계가 있다면 false
            checker = false;
            break;
        }
    }
    return checker;
}