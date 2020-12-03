/*
문제 소풍
 학생 수와 각 학생들이 서로 친구인지에 대한 여부가 주어졌을 때 각 학생들끼리 짝을 지을 수 있는 경우의 수를 구하는 프로그램을 작성하지오

입력
 입력의 첫 줄에는 테스트 케이스의 수 C(C<=50)가 주어집니다.
 각 테스트 케이스의 첫 줄에는 학생의 수 c(2<=n<=10)과 친구 쌍의 수m(0<=m<=n*(n+1)/2)이 주어집니다.
 그 다음 줄에 m개의 정수 쌍으로 서로 친구인 두 학생의 번호가 주어집니다.
 번호는 모두 0부터 n-1 사이의 정수이고, 같은 쌍은 입력에 두 번 주어지지 않습니다.
 학생들의 수는 짝수입니다.
 
 출력
 각 테스트 케이스마다 한 줄에 모든 학생을 친구끼리만 짝지어 줄 수 있는 방법의 수를 출력합니다.
 */

/*
풀이
재귀함수를 이용한 완전탐색으로 모든 경우의 수를 살펴본다.
이떄 중복되는 경우를 제외하기 위해 작은 번호부터 순서대로 쌍을 지어준다.
*/

#include <iostream>
#include <vector>

using namespace std;

int countCases(bool picked[10], int n); //경우의 수를 세는 함수
bool checkNoting(int n, int m); //예외처리 함수

bool areFriend[10][10] = { 0 }; //친구인 경우의 수
int n, m;                       //학생 수와 친구인 쌍의 수

int main()
{
    int c;                      //테스트 케이스
    int tmp1, tmp2;
    bool picked[10] = { 0 };    //각 학생들이 이미 쌍을 지었는지의 여부

    cin >> c;   //테스트 케이스 수 입력
    for (int j = 0; j < c; j++) {
        cin >> n >> m;  //학생 수와 친구인 쌍의 개수 입력
        for (int i = 0; i < m; i++) {   //서로 친구인 쌍 입력
            cin >> tmp1 >> tmp2;
            areFriend[tmp1][tmp2] = true;
            areFriend[tmp2][tmp1] = true;
        }

        if (!checkNoting(n, m)) //예외처리, 경우의 수가 하나도 없는 경우
            cout << 0 << endl;
        else
            cout << countCases(picked, n) << endl;
        for (int k = 0; k < 10; k++)
            for (int h = 0; h < 10; h++)
                areFriend[k][h] = false;
    }

    return 0;
}

int countCases(bool picked[10], int n) {
    int num=0;
    int smallest=0;
    while (picked[smallest]) //짝지어지지 않은 가장 작은 번호 찾기
        smallest += 1;
    picked[smallest] = true;
    for (int i = smallest; i < n - 1; i++) {
        if (!picked[i + 1] && areFriend[smallest][i+1]) {   //짝지어지지 않은 가장 작은 번호의 학생과 짝을 이루게하기
            picked[i + 1] = true;
            num += 1 + countCases(picked, n - 2);           //나머지 학생들을 짝지어주기
            picked[i + 1] = false;
        }
    }
    picked[smallest] = false;
    return num;
}

bool checkNoting(int n, int m) {
    if (m < n / 2) //친구 쌍의 수가 학생들이 한번에 짝을 짓는 수보다 작을 경우
        return false;
    for (int i = 0; i < n/2; i++) { //친구가 아예 없는 학생이 있는 경우
        for (int j = i; j < n; j++) {
            if (areFriend[i][j + 1])
                break;
            if (j == n - 1)
                return false;
        }
    }
    return true;
}