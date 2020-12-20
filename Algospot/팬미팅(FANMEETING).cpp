/*
���� - �ҹ���(FANMEETING)(https://algospot.com/judge/problem/read/FANMEETING)
 ���� ����� ���� ���̵� �׷����� ��׽� �Ͽ� �ö� �ִ� ȥ�� �� �׷� �����۽ôϾ ���� 10�ֳ� ��� �� ������ �����߽��ϴ�.
 �� ������ �� ������, ������ ������ �ҵ��� ������ �ϴ� ��縦 ����� �߽��ϴ�. �����۽ôϾ��� ������� �켱 ���뿡 �Ϸķ� ���ϴ�.
 �� ���ÿ� ������ M���� �ҵ��� ���� ���� �� ������ ����������� ������ �� �� �������� �����̸� ������ �ϳ��� ������ �մϴ�.
 ��� �ҵ��� ���ÿ� �� �� �����Դϴ�. �Ʒ� �׸��� ��� ������ �Ϻθ� �����ݴϴ�. a~d�� �� ���� �����۽ôϾ� ������̰�, 0~5�� ���� ���� �ҵ��Դϴ�.

 ������ �����۽ôϾ��� ���� ������� ���� �Ұ� �����ϱⰡ �θ��ϴٰ� ���ܼ�, ���� �Ұ��� ���� ��� �Ǽ��� �ϱ�� �߽��ϴ�.
 ���� �� ������ �ҵ��� ������ ���� �־��� �� �� ������ ����Ǵ� �������� �����۽ôϾ��� ��� ����� ���ÿ� ������ �ϴ� ���� �� ���̳� �ִ��� ����ϴ� ���α׷��� �ۼ��ϼ���.

�Է�
 ù �ٿ� �׽�Ʈ ���̽��� ���� C (C��20)�� �־����ϴ�.
 �� �׽�Ʈ ���̽��� ������� ������ �ҵ��� ������ ���� ��Ÿ���� �� ���� ���ڿ��� �����Ǿ� �ֽ��ϴ�.
 �� ���ڿ��� ���ʺ��� ������ ������� �� ������� ������ ��Ÿ���ϴ�.
 M�� �ش��ϴ� ����� ����, F�� �ش��ϴ� ����� �������� ��Ÿ���ϴ�.
 ����� ���� ���� ���� ��� 1 �̻� 200,000 ������ �����̸�, ����� ���� �׻� ���� �� �����Դϴ�.

���
 �� �׽�Ʈ ���̽����� �� �ٿ� ��� ������� ������ �ϴ� ���� �� ���̳� �ִ��� ����մϴ�.

Ǯ��
 �� ������ Ǯ �� ����for���� �̿��� ����Ž���� �� ���� �ִ�.
 ������ ����Ե� ī������ �˰����� �̿��ϸ� Ǯ �� �ִٴ� ����� �˰� �Ǿ���.
 M=1, F=0���� �Ͽ� �� ���� ���ϸ� �� �ڸ����� ���� �� ������ �ҵ��� ���������� ��Ÿ���� �ȴ�.
 ���ڳ��� ���� ��� 1, �� ���� ���� 0�� �ǹǷ� �̸� �̿��Ͽ� ���� ���θ� �Ǻ��� �� �ִ�.
*/
#include <iostream>
#include <vector>

using namespace std;

void nomalize(vector<int>& c) { //�ڸ��� �ø��� ó���ϴ� �Լ�
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

vector<int> multiply(vector<int>& a, vector<int>& b) {    //a*b ��ȯ�ϴ� �ð����⵵ O(n^n)�� �Լ�
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
    if (an < bn)    //a���� b�� �ڸ����� �� ū ���
        return karatsuba(b, a);
    if (an == 0 || bn == 0) //a�� b�� 0�� ���
        return vector<int>();
    if (an < 50)    //a�� �ڸ����� 50���ϸ� �׳� ���
        return multiply(a, b);
    //a, b�� ���� �ɰ���
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