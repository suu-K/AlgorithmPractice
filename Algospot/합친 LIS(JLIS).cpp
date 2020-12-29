/*
문제 - 합친 LIS(JLIS)(https://algospot.com/judge/problem/read/JLIS)
 어떤 수열에서 0개 이상의 숫자를 지운 결과를 원 수열의 부분 수열이라고 부릅니다. 예를 들어 '4 7 6'은 '4 3 7 6 9'의 부분 수열입니다.
 중복된 숫자가 없고 오름 차순으로 정렬되어 있는 부분 수열들을 가리켜 증가 부분 수열이라고 부르지요. 예를 들어 '3 6 9'는 앞의 수열의 증가 부분 수열입니다.
 두 개의 정수 수열 A 와 B 에서 각각 증가 부분 수열을 얻은 뒤 이들을 크기 순서대로 합친 것을 합친 증가 부분 수열이라고 부르기로 합시다.
 이 중 가장 긴 수열을 합친 LIS(JLIS, Joined Longest Increasing Subsequence)이라고 부릅시다.
 예를 들어 '1 3 4 7 9' 은 '1 9 4' 와 '3 4 7' 의 JLIS입니다. '1 9' 와 '3 4 7' 을 합쳐 '1 3 4 7 9'를 얻을 수 있기 때문이지요.
 A 와 B 가 주어질 때, JLIS의 길이를 계산하는 프로그램을 작성하세요.

입력
 입력의 첫 줄에는 테스트 케이스의 수 c ( 1 <= c <= 50 ) 가 주어집니다.
 각 테스트 케이스의 첫 줄에는 A 와 B 의 길이 n 과 m 이 주어집니다 (1 <= n,m <= 100).
 다음 줄에는 n 개의 정수로 A 의 원소들이, 그 다음 줄에는 m 개의 정수로 B 의 원소들이 주어집니다.
 모든 원소들은 32비트 부호 있는 정수에 저장할 수 있습니다.

출력
 각 테스트 케이스마다 한 줄에, JLIS 의 길이를 출력합니다.

풀이
 앞서 풀었던 최대 증가 부분 수열(LIS) 문제의 확장판이다. 이번엔 각 두 수열의 부분 증가수열을 합쳐서 최대가 되야 하므로 양쪽 수열을 번갈아가며 완전탐색을 진행해야 한다.
 처음에는 주어지는 수들의 범위가 32비트 정수형이라는 것을 놓쳐 계속 오류를 내었다.
 이를 막기 위해서는 주어지는 수들의 최소값이 int형의 최소값이므로 처음 시작할 때 두는 최소값을 64비트 정수형의 최소값으로 두어야 한다.

*/


#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const long long NEGINT = numeric_limits<long long>::min();  //64비트 정수 최소값

int a[100]; //수열 a
int b[100]; //수열 b
int cache[101][101];    //메모이제이션용 캐쉬
int n, m;   //a, b의 각각의 길이

int jlis(int idxA, int idxB) {  //a, b의 각각의 인데스값
    int& ret = cache[idxA + 1][idxB + 1];   //idxa, idxb부터 시작하는 최대 증가 부분 수열의 값
    if (ret != -1) return ret;              //이미 구한 값이라면 바로 반환
    ret = 2;                                //a[idxA], b[idxB]가 증가 부분 수열을 이룰 때의 최소값

    //해당 인덱스에서의 최대값 구하기
    long long an = (idxA == -1 ? NEGINT : a[idxA]);
    long long bn = (idxB == -1 ? NEGINT : b[idxB]);
    long long maximum = max(an, bn);
    //a의 다음 수가 현재의 최대값보다 크다면 인덱스 이동
    for (int next = idxA + 1; next < n; next++)
        if (maximum < a[next])
            ret = max(ret, jlis(next, idxB) + 1);
    //b의 다음 수가 현재의 최대값보다 크다면 인덱스 이동
    for (int next = idxB + 1; next < m; next++)
        if (maximum < b[next])
            ret = max(ret, jlis(idxA, next) + 1);
    return ret;
}

//테스트 케이스마다 배열을 초기화
void reset() {
    for (int i = 0; i < 100; i++) {
        a[i] = -1;
        b[i] = -1;
    }
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++)
            cache[i][j] = -1;
    }
    return;
}

int main() {
    int c;
    int tmp;
    reset();
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> n >> m;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            a[j] = tmp;
        }
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            b[j] = tmp;
        }
        cout << jlis(-1, -1) - 2 << endl;   //최초 시작 위치가 (-1, -1)이므로 2를 빼줘야 한다.
        reset();
    }
    return 0;
}