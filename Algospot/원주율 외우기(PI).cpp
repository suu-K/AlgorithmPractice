/*
문제 - 원주율 외우기(PI)(https://algospot.com/judge/problem/read/PI)
 가끔 TV 에 보면 원주율을 몇만 자리까지 줄줄 외우는 신동들이 등장하곤 합니다.
 이들이 이 수를 외우기 위해 사용하는 방법 중 하나로, 숫자를 몇 자리 이상 끊어 외우는 것이 있습니다.
 이들은 숫자를 세 자리에서 다섯 자리까지로 끊어서 외우는데, 가능하면 55555 나 123 같이 외우기 쉬운 조각들이 많이 등장하는 방법을 택하곤 합니다.

 이 때, 각 조각들의 난이도는 다음과 같이 정해집니다:
    모든 숫자가 같을 때 (예: 333, 5555) 난이도: 1
    숫자가 1씩 단조 증가하거나 단조 감소할 때 (예: 23456, 3210) 난이도: 2
    두 개의 숫자가 번갈아 가며 출현할 때 (예: 323, 54545) 난이도: 4
    숫자가 등차 수열을 이룰 때 (예: 147, 8642) 난이도: 5
    그 외의 경우 난이도: 10

 원주율의 일부가 입력으로 주어질 때, 난이도의 합을 최소화하도록 숫자들을 3자리에서 5자리까지 끊어 읽고 싶습니다
 최소의 난이도를 계산하는 프로그램을 작성하세요.

입력
 입력의 첫 줄에는 테스트 케이스의 수 C (<= 50) 가 주어집니다.
 각 테스트 케이스는 8글자 이상 10000글자 이하의 숫자로 주어집니다.

출력
 각 테스트 케이스마다 한 줄에 최소의 난이도를 출력합니다.

풀이
 단순히 완전탐색으로만 풀었을 때 자리수가 클 때 숫자를 3~5자리로 나누는 수가 너무 많아 시간초과가 났다.
 이를 줄이기 위해 메모이제이션을 적용했더니 시간 안에 풀렸다.
 입력받은 숫자를 각 자릿수별로 끊어 수열로 나누고 해당 수열을 3,4,5로 각각 끊어서 검사해 재귀함수를 이용해 완전탐색을 하였다.
*/


#include <iostream>
#define MAXNUM 100000   //가장 큰 난이도일때보다 큰 값

using namespace std;

int arr[10000];     //입력받은 숫자를 한자리씩 끊은 배열
int cache[10000];   //메모이제이션 용 배열
int n = 0;          //입력받은 수의 자릿수

void reset() {      //테스트 케이스가 끝났을 떄 초기화 함수
    for (int i = 0; i < 10000; i++) {
        arr[i] = -1;
        cache[i] = MAXNUM;
    }
    n = 0;
    return;
}

int check(int idx, int n) { //인덱스 주소가 주어졌을 때 숫자 n개의 난이도 조사
    bool same = true;
    int inc = arr[idx + 1] - arr[idx];

    for (int i = 1; i < n; i++) {
        if (!same || arr[idx + i - 1] != arr[idx + i])
            same = false;
        if (arr[idx + i] - arr[idx + i - 1] != inc)
            inc = 0;
    }
    if (same)       //모든 숫자가 같을 떄
        return 1;
    else if (inc == 1 || inc == -1)  //단조 증가 혹은 단조 감소일때
        return 2;
    else if (inc != 0)  //등차수열을 이룰 떄
        return 5;

    for (int i = 0; i < n - 2; i++) {   //숫자가 반복되지도 않을 때
        if (arr[idx + i] != arr[idx + i + 2])
            return 10;
    }
    return 4;       //숫자가 반복되어 나타날 떄
}

int piLevel(int idx) {          //난이도 조사 함수
    int& ret = cache[idx];
    if (ret != MAXNUM)          //만약 계산해 놓은 값이 이미 있다면 반환
        return ret;
    int rest = n - idx;         //남은 숫자의 개수
    if (rest < 3)               //남은 숫자가 3개 이하면 최대값 반환
        return ret;
    else if (rest >= 3 && rest <= 5)    //남은 숫자가 3~5개면 검사
        return check(idx, rest);
    for (int i = 3; i <= 5; i++)       //3,4,5개씩 끊어서 각각 검사해보기
        ret = min(ret, check(idx, i) + piLevel(idx + i));
    return ret;
}

int main() {
    int c, tmp;
    cin >> c;
    getchar();
    for (int i = 0; i < c; i++) {
        reset();
        while ((tmp = getchar()) != '\n') {
            arr[n] = tmp - '0';
            n++;
        }
        cout << piLevel(0) << endl;
    }
    return 0;
}