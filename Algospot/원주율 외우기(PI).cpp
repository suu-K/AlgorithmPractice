/*
문제 - 원주율 외우기(PI)(https://algospot.com/judge/problem/read/PI)

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