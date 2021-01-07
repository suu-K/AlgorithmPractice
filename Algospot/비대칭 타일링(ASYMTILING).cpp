/*
문제 - 비대칭 타일링(ASYMTILING)(https://algospot.com/judge/problem/read/ASYMTILING)

풀이
    문제의 핵심은 비대칭 타일링을 구하는 것보다 대칭 타일링을 구하는 것이 더 쉽다는 것이다.
    따라서 비대칭 타일링의 수는 전체 타일링에서 대칭 타일링을 빼면 된다.
    대칭 타일링은 2가지 경우로 나뉘는데 길이가 n일때 n이 홀수면 가운데에 세로로된 타일을 무조건 놓아야 하고,
    짝수라면 가운데를 기준으로 좌우로 나누거나 가운데 2칸에 가로로된 타일 2개를 놓으면 된다.
*/


#include <iostream>
#define MOD 1000000007

using namespace std;

int cache[100];

void reset() {  //캐시 리셋
    for (int i = 0; i < 100; i++)
        cache[i] = -1;
    return;
}

int tiling(int idx, int n) {    //길이가 n일때 타일링할 수 있는 방법의 수
    if (idx == n)   //길이가 딱 맞으면 1 반환
        return 1;
    if (idx > n)    //길이를 넘겼으면 0 반환
        return 0;

    int& ret = cache[idx];
    if (ret != -1) return ret;

    ret = 0;
    ret += tiling(idx + 2, n) + tiling(idx + 1, n);    //1자 타일을 하나 놓은 경우의 수와 가로로 2개를 놓은 경우의 수의 합
    return ret %= MOD;
}


int asymtiling(int n) { //길이가 n인 비대칭 타일링의 경우의 수
    int ret;
    int nt = tiling(0, n);  //전체를 타일링 하는 경우의 수
    reset();
    int dnt = tiling(0, n / 2); //(절반만 타일링하는 경우의 수) = (좌우 대팅인 경우의 수)
    if (n % 2 == 0) {   //길이가 짝수면
        reset();
        ret = nt - dnt - tiling(0, n / 2 - 1);  //(전체 경우의 수) - (절반만 타일링 한 경우의 수) - (가운데 2칸을 놓고 한 경우의 수)
    }
    else {              //길이가 홀수면
        ret = nt - dnt;
    }
    while (ret < 0) {   //나머지가 음수라면 양수로 변환
        ret += MOD;
    }
    return ret;
}

int main() {
    int c = 0;
    int n = 0;
    cin >> c;
    for (int i = 0; i < c; i++) {
        reset();
        cin >> n;
        cout << asymtiling(n) << endl;
    }
    return 0;
}