/*
문제 - 최대 증가 부분 수열(LIS)(https://algospot.com/judge/problem/read/LIS)
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int cache[501];

int lis(int start) {
    int& ret = cache[start + 1];
    if (ret != -1) return ret;
    ret = 1;
    for (int i = start + 1; i < a.size(); i++) {
        if (start == -1 || a[start] < a[i])
            ret = max(ret, 1 + lis(i));
    }
    return ret;
}


void reset() {
    a.clear();
    for (int i = 0; i < 501; i++) {
        cache[i] = -1;
    }
    return;
}

int main() {
    int c;
    int n;
    int tmp;
    reset();
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            a.push_back(tmp);
        }
        cout << lis(-1) - 1 << endl;
        reset();
    }
    return 0;
}