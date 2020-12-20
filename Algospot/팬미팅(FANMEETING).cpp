/*
문제 - 팬미팅(FANMEETING)(https://algospot.com/judge/problem/read/FANMEETING)
 가장 멤버가 많은 아이돌 그룹으로 기네스 북에 올라 있는 혼성 팝 그룹 하이퍼시니어가 데뷔 10주년 기념 팬 미팅을 개최했습니다.
 팬 미팅의 한 순서로, 멤버들과 참가한 팬들이 포옹을 하는 행사를 갖기로 했습니다. 하이퍼시니어의 멤버들은 우선 무대에 일렬로 섭니다.
 팬 미팅에 참가한 M명의 팬들은 줄을 서서 맨 오른쪽 멤버에서부터 시작해 한 명씩 왼쪽으로 움직이며 멤버들과 하나씩 포옹을 합니다.
 모든 팬들은 동시에 한 명씩 움직입니다. 아래 그림은 행사 과정의 일부를 보여줍니다. a~d는 네 명의 하이퍼시니어 멤버들이고, 0~5는 여섯 명의 팬들입니다.

 하지만 하이퍼시니어의 남성 멤버들이 남성 팬과 포옹하기가 민망하다고 여겨서, 남성 팬과는 포옹 대신 악수를 하기로 했습니다.
 줄을 선 멤버들과 팬들의 성별이 각각 주어질 때 팬 미팅이 진행되는 과정에서 하이퍼시니어의 모든 멤버가 동시에 포옹을 하는 일이 몇 번이나 있는지 계산하는 프로그램을 작성하세요.

입력
 첫 줄에 테스트 케이스의 개수 C (C≤20)가 주어집니다.
 각 테스트 케이스는 멤버들의 성별과 팬들의 성별을 각각 나타내는 두 줄의 문자열로 구성되어 있습니다.
 각 문자열은 왼쪽부터 오른쪽 순서대로 각 사람들의 성별을 나타냅니다.
 M은 해당하는 사람이 남자, F는 해당하는 사람이 여자임을 나타냅니다.
 멤버의 수와 팬의 수는 모두 1 이상 200,000 이하의 정수이며, 멤버의 수는 항상 팬의 수 이하입니다.

출력
 각 테스트 케이스마다 한 줄에 모든 멤버들이 포옹을 하는 일이 몇 번이나 있는지 출력합니다.

풀이
 이 문제를 풀 떄 이중for문을 이용해 완전탐색을 할 수도 있다.
 하지만 놀랍게도 카라츠바 알고리즘을 이용하면 풀 수 있다는 사실을 알게 되었다.
 M=1, F=0으로 하여 두 수를 곱하면 각 자리수의 값이 각 멤버들과 팬들의 남녀조합을 나타내게 된다.
 남자끼리 만날 경우 1, 그 외의 경우는 0이 되므로 이를 이용하여 포옹 여부를 판별할 수 있다.
*/
#include <iostream>
#include <vector>

using namespace std;

void nomalize(vector<int>& c) { //자리수 올림을 처리하는 함수
    int cn = c.size();
    c.push_back(0);
    for (int i = 0; i < cn; i++) {
        if (c[i] < 0) {
            int tmp = (abs(c[i]) + 9) / 10;
            c[i + 1] -= tmp;
            c[i] += tmp * 10;
        }
        else {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
}

vector<int> multiply(vector<int>& a, vector<int>& b) {    //a*b 반환하는 시간복잡도 O(n^n)의 함수
    int an = a.size();
    int bn = b.size();
    vector<int> c(an + bn + 1, 0);
    for (int i = 0; i < an; i++) {
        for (int j = 0; j < bn; j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    //nomalize(c);
    return c;
}

void addTo(vector<int>& a, vector<int>& b, int n) {   //a += b * 10^n
    int an = a.size(), bn = b.size();
    a.resize(max(an, bn + n));
    for (int i = 0; i < bn; i++)
        a[i + n] += b[i];
    //nomalize(a);
}

void subFrom(vector<int>& a, vector<int>& b) {
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < b.size(); i++)
        a[i] -= b[i];
    //nomalize(a);
}


vector<int> karatsuba(vector<int> a, vector<int> b) {
    int an = a.size(), bn = b.size();
    int half = an / 2;
    if (an < bn)    //a보다 b의 자리수가 더 큰 경우
        return karatsuba(b, a);
    if (an == 0 || bn == 0) //a나 b가 0인 경우
        return vector<int>();
    if (an < 50)    //a의 자리수가 50이하면 그냥 계산
        return multiply(a, b);
    //a, b를 각각 쪼갠다
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + half);
    vector<int> b1(b.begin() + half, b.end());

    vector<int> z1 = karatsuba(a1, b1); //z1=a1*b1
    vector<int> z3 = karatsuba(a0, b0); //z3=a0*b0

    //z2=(a1+a0)*(b1+b0)-z1-z3
    addTo(a0, a1, 0);
    addTo(b0, b1, 0);
    vector<int> z2 = karatsuba(a0, b0);
    subFrom(z2, z1);
    subFrom(z2, z3);

    //z=z1*10^2h + z2*10^h + z3
    vector<int> z;
    addTo(z, z1, 2 * half);
    addTo(z, z2, half);
    addTo(z, z3, 0);

    return z;
}

int calc(string mem, string fan) {
    int mn = mem.size(), fn = fan.size();
    vector<int> m(mn), f(fn);
    for (int i = 0; i < mn; i++) {
        if (mem[i] == 'M')
            m[i] = 1;
        else
            m[i] = 0;
    }
    for (int i = 0; i < fn; i++) {
        if (fan[i] == 'M')
            f[fn - i - 1] = 1;
        else
            f[fn - i - 1] = 0;
    }
    vector<int> c = karatsuba(m, f);
    int n = 0;
    for (int i = mn - 1; i < fn; i++)
        if (c[i] == 0)
            n++;
    return n;
}

int main() {
    int c;
    string mem, fan;
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> mem >> fan;
        cout << calc(mem, fan) << endl;
    }
    return 0;
}