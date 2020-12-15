/*
문제 - 울타리 잘라내기(FENCE)(https://algospot.com/judge/problem/read/FENCE)
 너비가 같은 N개의 나무 판자를 붙여 세운 울타리가 있습니다.
 시간이 지남에 따라 판자들이 부러지거나 망가져 높이가 다 달라진 관계로 울타리를 통째로 교체하기로 했습니다.
 이 때 버리는 울타리의 일부를 직사각형으로 잘라내 재활용하고 싶습니다.
 그림 (b)는 (a)의 울타리에서 잘라낼 수 있는 많은 직사각형 중 가장 넓은 직사각형을 보여줍니다.
 울타리를 구성하는 각 판자의 높이가 주어질 때, 잘라낼 수 있는 직사각형의 최대 크기를 계산하는 프로그램을 작성하세요.
 단 (c)처럼 직사각형을 비스듬히 잘라낼 수는 없습니다.

 판자의 너비는 모두 1이라고 가정합니다.

입력
 첫 줄에 테스트 케이스의 개수 C (C≤50)가 주어집니다.
 각 테스트 케이스의 첫 줄에는 판자의 수 N (1≤N≤20000)이 주어집니다.
 그 다음 줄에는 N개의 정수로 왼쪽부터 각 판자의 높이가 순서대로 주어집니다.
 높이는 모두 10,000 이하의 음이 아닌 정수입니다.

출력
 각 테스트 케이스당 정수 하나를 한 줄에 출력합니다.
 이 정수는 주어진 울타리에서 잘라낼 수 있는 최대 직사각형의 크기를 나타내야 합니다.

 풀이
  기준이 되는 판자의 높이에서 구할 수 있는 최대 너비를 구하였다.
  i번 판자의 높이가 h라고 하면 h와 같거나 높은 연속된 판자의 너비를 구해서 넓이를 구하는 식으로 하였다.
*/
#include <iostream>
#include <vector>

using namespace std;

int maxSize(vector<int>& fence) {
    int maxSize = 0;    //최대 넓이
    int h = 0, w = 0, left = 0, right = 0;
    for (int i = 0; i < fence.size(); i++) {
        h = fence[i];   //기준이 되는 펜스의 높이
        left = i;       //가장 왼쪽 판자
        maxSize = max(maxSize, fence[left]);    //판자 하나의 넓이
        right = i + 1;                          //가장 오른쪽 판자
        while (left >= 0 && fence[left] >= h) { left--; } left++;       //가장 왼쪽에 있는 현재 높이보다 작지 않은 연속된 판자
        while (right < fence.size() && fence[right] >= h) { right++; }  //가장 오른쪽에 있는 현재 높이보다 작지 않은 연속된 판자
        w = right - left;   //판자의 너비
        maxSize = max(maxSize, h * w);  //판자의 최대 넓이
    }
    return maxSize;
}


int main() {
    int c;
    int n, tmp;
    vector<int> fence;
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            fence.push_back(tmp);
        }
        cout << maxSize(fence) << endl;
        fence.clear();
    }
    return 0;
}