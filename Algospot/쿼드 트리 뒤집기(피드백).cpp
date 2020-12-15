/*
피드백 - 쿼드 트리 뒤집기(QUADTREE)(https://algospot.com/judge/problem/read/QUADTREE)
 책의 정답에서는 iterator를 이용해 좀 더 깔끔하게 문제를 풀어주었다.
 처음에 문제를 풀었을 떄 가장 까다로웠던 부분이 다음 문자열로 어떻게 넘어가는가 였다.
 나의 경우에는 반환된 문자열의 길이를 이용했지만 이처럼 iterator를 이용해 한칸씩 전진시키면 훨씬 코드가 깔끔해진다.
*/
#include <iostream>
#include <vector>

using namespace std;

string reverse(string::iterator& it) {
    char head = *it;
    string part[4];
    ++it;
    if (head == 'w' || head == 'b')
        return string(1, head);
    part[0] = reverse(it);
    part[1] = reverse(it);
    part[2] = reverse(it);
    part[3] = reverse(it);
    return "x" + part[2] + part[3] + part[0] + part[1];
}

int main() {
    int c;
    string picture;
    string::iterator it;
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> picture;
        it = picture.begin();
        cout << reverse(it) << endl;
        picture.clear();
    }

    return 0;
}