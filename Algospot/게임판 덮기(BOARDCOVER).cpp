/*
문제 : 게임판 덮기(BORARDCOVER)(https://algospot.com/judge/problem/read/BOARDCOVER)

풀이
재귀함수를 이용한 완전탐색으로 모든 경우의 수를 살펴본다.
이떄 중복되는 경우를 제외하기 위해 가장 왼쪽 위의 칸부터 채워나간다.
*/

#include <iostream>
#include <vector>

using namespace std;

int count(vector<vector<int>> &board, int h, int w);
bool cover(vector<vector<int>> &board, int y, int x, int n, int h, int w, int pivot);

const int block[4][3][2] = {        //블럭 모양
    {{0,0},{0,1},{1,0}},    //r
    {{0,0},{0,1},{1,1}},    //ㄱ
    {{0,0},{1,0},{1,1}},    //ㄴ
    {{0,0},{1,0},{1,-1}}    //J
};


int main()
{
    int c = 0; //테스트 케이스
    int h = 0, w = 0;
    vector<vector<int>> board; //게임 보드판. 검정색이면 1, 흰색이면 0
    char tmp;
    
    int wnum = 0, bnum = 0;
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> h >> w;
        for (int j = 0; j < h; j++) {
            vector<int> temp;
            for (int k = 0; k < w; k++) {
                cin >> tmp;
                if (tmp == '#')
                    temp.push_back(1);
                else if (tmp == '.') {
                    temp.push_back(0);
                    wnum++;
                }
            }
            board.push_back(temp);
        }

        if (wnum % 3 != 0)      //흰 칸의 수가 3배수가 아니면 무조건 실패
            cout << 0 << endl;
        else
            cout << count(board, h, w) << endl;

        wnum = 0;           //흰칸 수와 보드판 초기화
        board.clear();
    }
    return 0;
}

int count(vector<vector<int>> &board, int h, int w) {
    int num = 0;
    int x=-1, y=-1;
    //가장 왼쪽 위 찾기
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (board[i][j] == 0) { //가장 위의 비어있는 왼쪽 칸을 찾았으면
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1)
            break;
    }
    if (y == -1)    //모든 빈칸을 채웠으면 1반환
        return 1;


    for (int i = 0; i < 4; i++) {   //해당 위치에 4가지 블럭을 하나씩 넣어보기
        if (cover(board, y, x, i, h, w, 1)) {
            num += count(board, h, w);
        }
        cover(board, y, x, i, h, w, -1);
    }


    return num;
}

bool cover(vector<vector<int>> &board, int y, int x, int n, int h, int w, int pivot) {    //y,x자리에 n번쨰 블럭을 pivot이 1이면 채우고 0이면 비운다.
    int nx = x;
    int ny = y;
    bool check = true;
    for (int i = 0; i <= 2; i++) {
        nx = x+block[n][i][1];
        ny = y+block[n][i][0];
        if (nx >= w || ny >= h || nx < 0 || ny < 0) {   //블럭이 게임판을 벗어났을 경우
            check = false;
        }
        else if ((board[ny][nx] += pivot) > 1)          //검은 칸 위에 블럭을 놓았을 경우
            check = false;
    }

    return check;
}

