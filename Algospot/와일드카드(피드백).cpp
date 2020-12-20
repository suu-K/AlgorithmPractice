/*
피드맥 - 와일드카드(WILDCARD)(https://algospot.com/judge/problem/read/WILDCARD)
    이 문제를 처음 풀 때는 반복문 및 재귀호출 을 이용하여 완전탐색으로 풀었다.
    하지만 이는 중간에 같은 경우이지만 중복되는 문제들을 여러번 계산한다는 문제가 있다.
    이를 해결하는 방법이 Dynamic Programing, 줄여서 dp이다. dp에서도 메모제이션을 이용하면 여러번 계산 되는 것을 막을 수 있다.
    각 글자의 길이가 100자 이내이기 때문에 100 by 100의 배열에 떼어낸 부분문제들이 이미 결과를 내었는지 저장해 놓는 것이다.
    그를 위해 반복문을 재귀함수를 이용하는 문제로 바꿔주면 시간복잡도가 줄어든다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cache[101][101];
string wc, str;

int func(int w, int s) {
    int& ret = cache[w][s];
    if (ret != -1) return ret;
    if (w < wc.size() && s < str.size() && (wc[w] == '?' || wc[w] == str[s]))
        return ret = func(w + 1, s + 1); //포인터의 글자가 같거나 각 단어의 끝이 아닐때 통과
    //두 단어 중 하나가 끝에 도달했다면
    if (wc.size() == w)   //두 단어의 길이가 같을 떄 참
        return ret = (s == str.size());
    if (wc[w] == '*') {   //*가 나왔다면
        for (int j = 0; j + s <= str.size(); j++) { //*가 0글자부터 한글자씩 늘려가며 몇 글자를 차지하는지 찾아본다
            if (func(w + 1, s + j))
                return ret = 1;
        }
    }
    //결국 하나도 맞지 않게 될 떄
    return ret = 0;
}

void cacheReset() {
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            cache[i][j] = -1;
    return;
}
void printCache() {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++)
            cout << cache[i][j];
        cout << endl;
    }
    return;
}

int main() {
    int c;
    int n;
    vector<string> word;
    cacheReset();
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> wc;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> str;
            func(0, 0);
            if (cache[0][0] == 1)
                word.push_back(str);
            cacheReset();

        }
        sort(word.begin(), word.end(), less<string>()); //내림차순 정렬
        for (int j = 0; j < word.size(); j++)
            cout << word[j] << endl;
        //한 테스트 케이스가 끝나면 초기화
        wc.clear();
        str.clear();
        word.clear();
    }
    return 0;
}