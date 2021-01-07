/*
문제 - 와일드카드(WILDCARD)(https://algospot.com/judge/problem/read/WILDCARD)

풀이
 결국 처음부터 끝까지 하나씩 경우의 수를 살펴보는 식으로 하였다.
 처음부터 한글자씩 비교해서 각 단어가 끝날 떄, 문자가 같지 않을때, *이 나왔을 때까지 비교한다음 경우의 수를 따져봤다.
 각 단어가 끝났을 떄 서로 길이가 같다면 두 단어는 같은 것이다. 만약 다르다면 *이 있다면 같을 수 있다.
 두 단어가 다를 때는 *가 아닌 이상 둘은 다른 단어다.
 *가 나왔으면 *가 0부터 몇글자를 차지하는 지를 모르기 때문에 한글자씩 늘려가며 모든 경우의 수를 찾아본다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool func(const string& wc, const string& word) {
    int ptr;
    for (ptr = 0; ptr < wc.size() && ptr < word.size() && (wc[ptr] == '?' || wc[ptr] == word[ptr]); ptr++) {} //포인터의 글자가 같거나 각 단어의 끝이 아닐때 통과
    //두 단어 중 하나가 끝에 도달했다면
    if (wc.size() == ptr)   //두 단어의 길이가 같을 떄 참
        return ptr == word.size();
    if (wc[ptr] == '*') {   //*가 나왔다면
        for (int j = 0; j + ptr <= word.size(); j++) { //*가 0글자부터 한글자씩 늘려가며 몇 글자를 차지하는지 찾아본다
            if (func(wc.substr(ptr + 1), word.substr(ptr + j))) {
                return true;
            }
        }
    }
    //결국 하나도 맞지 않게 될 떄
    return false;
}

bool dec(const string& a, const string& b) {
    return a > b;
}


int main() {
    int c;
    int n;
    string wc;
    string tmp;
    vector<string> word;
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> wc;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (func(wc, tmp))
                word.push_back(tmp);
        }
        sort(word.begin(), word.end(), less<string>());
        for (int j = 0; j < word.size(); j++)
            cout << word[j] << endl;
        wc.clear();
        tmp.clear();
        word.clear();
    }
    return 0;
}