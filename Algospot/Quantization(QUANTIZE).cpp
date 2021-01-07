/*
문제 - Quantization(QUANTIZE)(https://algospot.com/judge/problem/read/QUANTIZE)

풀이
 이 문제의 핵심은 주어진 수열을 양자화시킬 수의 개수만큼 묶음을 지어주는 것이다.
 이 때 같은 양자화된 수를 가지는 수들은 서로 인접할 것이므로 입력받은 수열을 정렬한 후 앞에서부터 한 묶음에 몇개씩 넣을지 구분지어주면 된다.
 또한 해당 문제에서 한 묶음이 가지는 최소 오차의 제곱의 합은 결국 분산을 뜻하는 것이므로 양자수는 해당 묶음에 있는 수들의 평균이다.
*/


#include <iostream>
#include <vector>
#include <algorithm>

#define MAXNUM 999999999

using namespace std;

vector<int> v;
int cache[100][10];

void reset() {
    v.clear();
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
            cache[i][j] = MAXNUM;
        }
    }
}

int variance(int idx, int n) {  //idx부터 n개의 오차 제곱의 합의 최소값을 구하는 함수
    int sum = 0;
    int avg = 0;
    int ret1 = 0, ret2 = 0;
    for (int i = 0; i < n; i++)
        sum += v[idx + i];
    avg = sum / n;
    for (int i = 0; i < n; i++) {
        ret1 += pow(v[idx + i] - avg, 2);
    }
    for (int i = 0; i < n; i++) {
        ret2 += pow(v[idx + i] - avg - 1, 2);
    }
    return min(ret1, ret2);
}

int quantize(int idx, int s) {  //idx부터 수열을 s가지로 나누어 양자화하는 함수
    if (idx == v.size())    //남은 수들이 없으면 0 반환
        return 0;
    int& ret = cache[idx][s];
    if (ret != MAXNUM)          //이미 한번 구한 값이면 반환
        return ret;
    if (s == 1)                  //마지막 묶음이면 남은 수들의 최소 오차 제곱합을 반환
        return variance(idx, v.size() - idx);
    if (s > v.size() - idx)     //만일 조각 수가 남은 숫자의 개수보다 많으면 숫자의 개수만큼으로 바꿔줌
        s = v.size() - idx;
    if (s > 10)
        s = 10;
    for (int i = 1; i + idx <= v.size() - s + 1; i++) { //현재 idx에서 i개만큼 묶고 나머지를 s-1묶음으로 양자화
        ret = min(ret, variance(idx, i) + quantize(idx + i, s - 1));
    }
    return ret;
}

int main() {
    int c = 0;
    int n = 0, s = 0, tmp = 0;
    cin >> c;
    for (int i = 0; i < c; i++) {
        reset();
        cin >> n >> s;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end(), greater<int>());   //수열을 오름차순으로 정렬
        cout << quantize(0, s) << endl;
    }
    return 0;
}