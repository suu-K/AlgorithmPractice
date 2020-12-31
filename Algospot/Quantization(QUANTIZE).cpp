/*
문제 - Quantization(QUANTIZE)(https://algospot.com/judge/problem/read/QUANTIZE)
 Quantization (양자화) 과정은, 더 넓은 범위를 갖는 값들을 작은 범위를 갖는 값들로 근사해 표현함으로써 자료를 손실 압축하는 과정을 말한다.
 예를 들어 16비트 JPG 파일을 4컬러 GIF 파일로 변환하는 것은 RGB 색 공간의 색들을 4컬러 중의 하나로 양자화하는 것이고,
 키가 161, 164, 170, 178 인 학생 넷을 '160대 둘, 170대 둘' 이라고 축약해 표현하는 것 또한 양자화라고 할 수 있다.

 1000 이하의 자연수들로 구성된 수열을 최대 S종류 의 값만을 사용하도록 양자화하고 싶다.
 이 때 양자화된 숫자는 원래 수열에 없는 숫자일 수도 있다. 양자화를 하는 방법은 여러 가지가 있다.
 수열 1 2 3 4 5 6 7 8 9 10 을 2개의 숫자만을 써서 표현하려면, 3 3 3 3 3 7 7 7 7 7 과 같이 할 수도 있고, 1 1 1 1 1 10 10 10 10 10 으로 할 수도 있다.
 우리는 이 중, 각 숫자별 오차 제곱의 합을 최소화하는 양자화 결과를 알고 싶다.

 예를 들어, 수열 1 2 3 4 5 를 1 1 3 3 3 으로 양자화하면 오차 제곱의 합은 0+1+0+1+4=6 이 되고, 2 2 2 4 4 로 양자화하면 오차 제곱의 합은 1+0+1+0+1=3 이 된다.
 수열과 S 가 주어질 때, 가능한 오차 제곱의 합의 최소값을 구하는 프로그램을 작성하시오.

입력
 입력의 첫 줄에는 테스트 케이스의 수 C (1 <= C <= 50) 가 주어진다.
 각 테스트 케이스의 첫 줄에는 수열의 길이 N (1 <= N <= 100), 사용할 숫자의 수 S (1 <= S <= 10) 이 주어진다.
 그 다음 줄에 N개의 정수로 수열의 숫자들이 주어진다. 수열의 모든 수는 1000 이하의 자연수이다.

출력
 각 테스트 케이스마다, 주어진 수열을 최대 S 개의 수로 양자화할 때 오차 제곱의 합의 최소값을 출력한다.

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