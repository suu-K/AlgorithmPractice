/*
피드백 - 울타리 잘라내기(FENCE)(https://algospot.com/judge/problem/read/FENCE)
 처음에 문제를 풀 때에는 완전탐색에 가까운 알고리즘을 이용했지만 이럴 경우 n*n에 가까운 시간복잡도가 나온다.
 비록 예외 조건을 잘 설정하여 정답을 받아낼 수 있었지만 비효율적으로 보일 수 있다는 것을 알고있다.

 이 문제를 푸는 다른 방법은 분할 정복을 이용하는 풀이이다.
 가운데를 기준으로 요구하는 정답인 가장 큰 판자는 3가지 경우에서 나올 수 있다.
 1. 왼쪽 판자들 안에 있다.
 2. 오른쪽 판자들 안에 있다.
 3. 양쪽에 걸쳐져 있다.
 1,2번은 분할 문제로 재귀 호출을 이용하고 3번은 가운데에서부터 좌우로 확장해가며 탐색한다.
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> h;

int maxSize(int left, int right) {  //판자의 좌우 범위를 반환
    int ret = 0;
    if (left == right) return h[left];  //판자가 하나밖에 없을 경우
    int mid = (right + left) / 2;
    ret = max(maxSize(left, mid), maxSize(mid + 1, right)); //좌우로 분할

    //가운데 걸친 판자 중 가장 큰 것 찾기
    int l = mid, r = mid + 1;   //가운데 좌우 2칸
    int height = min(h[l], h[r]);
    ret = max(ret, height * (r - l + 1)); //현재 너비 2인 판자의 넓이
    while (left < l || r < right) {
        if (left < l && (r == right || h[l - 1] > h[r + 1]))  //왼쪽 다음 판자가 오른쪽 다음 판자보다 클떄
            height = min(height, h[--l]);   //왼쪽으로 한칸 확장
        else
            height = min(height, h[++r]);   //오른쪽으로 한칸 확장
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