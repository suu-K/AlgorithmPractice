/*
문제 - 울타리 잘라내기(FENCE)(https://algospot.com/judge/problem/read/FENCE)

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