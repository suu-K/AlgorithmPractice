/*
문제 쿼드 트리 뒤집기(QUADTREE)(https://algospot.com/judge/problem/read/QUADTREE)

풀이
 쿼드 트리는 재귀적으로 표현된다.
 이를 쉽게 처리 하기 위해서는 이것 또한 재귀적으로 처리하는 것이 좋다.
*/

#include <iostream>

using namespace std;

string reverse(string picture) {
    string tmp = picture;
    string part[4]; //part[0]-우상, part[1]-좌상, part[2]-우하, part[3]-좌하
    int n = 4;
    if (tmp.size() == 1) //문자열이 하나일 경우, 즉 그림이 단색일 경우
        return tmp;
    else if (tmp[0] != 'x') //그림의 조각이 단색일 경우
        return tmp.substr(0, 1);
    for (int i = 1, j = 0; i <= n; i++, j++) {  //4개의 조강을 따로따로 저장
        part[j] = reverse(tmp.substr(i));
        i += (part[j].size() - 1);    //x로 이루어진 조각을 건너뛴다.
        n += (part[j].size() - 1);
    }
    tmp = "x" + part[2] + part[3] + part[0] + part[1];  //각 조강의 상하를 뒤집는다.
    return tmp;
}

int main()
{
    string picture;;
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> picture;
        cout << reverse(picture) << endl;
    }
    return 0;
}
