/*
문제 게임판 덮기(https://algospot.com/judge/problem/read/BOARDCOVER)
H*W 크기의 게임판이 흰색과 검정색으로 이루어져 있다. 이떄 3칸으로 이루어진 L모양의 블럭으로 흰색칸을 가득 채울 수 있는 방법의 수

입력
 첫 줄에는 테스트 케이스 C의 수가 주어진다.
 각 테스트 케이스의 첫 줄에는 두개의 정수 H, W(1<=H,W<=20)이 주어진다.
 다음 H줄에 각 Wr가 글자로 게임판의 모양이 주어진다. #은 검은 칸, .은 흰칸을 나타낸다.
 입력에 주어지는 게임판에 있는 흰칸의 수는 50을 넘지 않는다.

출력
 한 줄에 하나씩 흰 칸을 모두 덮는 방법의 수를 출력한다.
 */

/*
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

