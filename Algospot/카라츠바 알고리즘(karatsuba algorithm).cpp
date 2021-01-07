/*
카라츠바 알고리즘(karatsuba algorithm)
    자리수가 너무 큰 수들은 배열에 저장해야 한다.
    이런 수들의 곱셈 방식을 일반적인 경우와 같이 한다면 시간 복잡도는 자리수가 n일때 O(n^n)이다.
    이를 개선시킨 것이 카라츠바 알고리즘이다.
    a*b에서 a = a1*10^n + a0, b = b1*10^n + b0로 각각을 쪼갠 뒤 곱셈을 하면
    a*b=(a1+b1)*10^2n + (a1*b0 + a0*b1) + a0*b0 이다.
    이렇게 계산하더라도 자리수가 n/2인 곱셈을 4번 하기 때문에 시간복잡도는 같지만 a1*b0 + a0*b1 = (a1 + 10)*(b1 + b0) - (a1+b1) - (a0*b0)를 이용하면 곱셈을 3번만 해도 된다.
    이를 그대로 구현한 곱셈 방식이 카라츠바 알고리즘이다.
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
    vector<int> c(an + bn, 0);
    for (int i = 0; i < an; i++) {
        for (int j = 0; j < bn; j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    nomalize(c);
    return c;
}

void addTo(vector<int>& a, vector<int>& b, int n) {   //a += b * 10^n
    int an = a.size(), bn = b.size();
    if (an < bn + n)
        a.resize(bn + n);
    for (int i = an; i < a.size(); i++)
        a[i] = 0;
    for (int i = 0; i < bn; i++)
        a[i + n] += b[i];
    nomalize(a);
}

void subFrom(vector<int>& a, vector<int>& b) {
    for (int i = 0; i < b.size(); i++)
        a[i] -= b[i];
    nomalize(a);
    return;
}

void printNum(vector<int> a) {
    if (a.size() == 0) {
        cout << 0 << endl;
        return;
    }
    for (int i = a.size() - 1; i >= 0; i--)
        cout << a[i];
    cout << endl;
    return;
}

vector<int> karatsuba(vector<int> a, vector<int> b) {
    int an = a.size(), bn = b.size();
    int half = an / 2;
    if (an < bn)    //a보다 b의 자리수가 더 큰 경우
        karatsuba(b, a);
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
    addTo(a1, a0, 0);
    addTo(b1, b0, 0);
    vector<int> z2 = karatsuba(a1, b1);
    subFrom(z2, z1);
    subFrom(z2, z3);

    //z=z1*10^2h + z2*10^h + z3
    vector<int> z;
    addTo(z, z1, 2 * half);
    addTo(z, z2, half);
    addTo(z, z3, 0);

    return z;
}

int main() {
    vector<int> a;
    vector<int> b;
    string an, bn;
    cin >> an >> bn;
    for (int i = an.size() - 1; i >= 0; i--)
        a.push_back(an[i] - '0');
    for (int i = bn.size() - 1; i >= 0; i--)
        b.push_back(bn[i] - '0');
    printNum(karatsuba(a, b));

    return 0;
}