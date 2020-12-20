/*
문제 - 와일드카드(WILDCARD)(https://algospot.com/judge/problem/read/WILDCARD)
 와일드카드는 다양한 운영체제에서 파일 이름의 일부만으로 파일 이름을 지정하는 방법이다.
 와일드카드 문자열은 일반적인 파일명과 같지만, * 나 ? 와 같은 특수 문자를 포함한다.
 와일드카드 문자열을 앞에서 한 글자씩 파일명과 비교해서, 모든 글자가 일치했을 떄 해당 와일드카드 문자열이 파일명과 매치된다고 하자.
 단, 와일드카드 문자열에 포함된 ?는 어떤 글자와 피교해도 일치한다고 가정하며, *는 0글자 이상의 어떤 문자열에도 일치한다고 본다.
 예를 들어 와일드 카드 he?p는 파일명 help에도, heap에도 매치되지만, helpp에는 매치되지 않는다.
 와일드카드 *p*는 파일명 help에도, papa에도 매치되지만, hello에는 매치되지 않는다.
 와일드카드 문자열과 함계 파일명의 집합이 주어질 떄, 그 중 매치되는 파일명들을 찾아내는 프로그램을 작성하시오.

입력
 입력의 첫 줄에는 테스트 케이스의 수 C (1 <= C <= 10) 가 주어진다.
 각 테스트 케이스의 첫 줄에는 와일드카드 문자열 W 가 주어지며, 그 다음 줄에는 파일명의 수 N (1 <= N <= 50) 이 주어진다.
 그 후 N 줄에 하나씩 각 파일명이 주어진다.
 파일명은 공백 없이 알파벳 대소문자와 숫자만으로 이루어져 있으며, 와일드카드는 그 외에 * 와 ? 를 가질 수 있다.
 모든 문자열의 길이는 1 이상 100 이하이다.

출력
 각 테스트 케이스마다 주어진 와일드카드에 매치되는 파일들의 이름을 한 줄에 하나씩 아스키 코드 순서(숫자, 대문자, 소문자 순)대로 출력한다.

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