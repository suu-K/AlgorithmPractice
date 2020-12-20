/*
�ǵ�� - ���ϵ�ī��(WILDCARD)(https://algospot.com/judge/problem/read/WILDCARD)
    �� ������ ó�� Ǯ ���� �ݺ��� �� ���ȣ�� �� �̿��Ͽ� ����Ž������ Ǯ����.
    ������ �̴� �߰��� ���� ��������� �ߺ��Ǵ� �������� ������ ����Ѵٴ� ������ �ִ�.
    �̸� �ذ��ϴ� ����� Dynamic Programing, �ٿ��� dp�̴�. dp������ �޸����̼��� �̿��ϸ� ������ ��� �Ǵ� ���� ���� �� �ִ�.
    �� ������ ���̰� 100�� �̳��̱� ������ 100 by 100�� �迭�� ��� �κй������� �̹� ����� �������� ������ ���� ���̴�.
    �׸� ���� �ݺ����� ����Լ��� �̿��ϴ� ������ �ٲ��ָ� �ð����⵵�� �پ���.
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
        return ret = func(w + 1, s + 1); //�������� ���ڰ� ���ų� �� �ܾ��� ���� �ƴҶ� ���
    //�� �ܾ� �� �ϳ��� ���� �����ߴٸ�
    if (wc.size() == w)   //�� �ܾ��� ���̰� ���� �� ��
        return ret = (s == str.size());
    if (wc[w] == '*') {   //*�� ���Դٸ�
        for (int j = 0; j + s <= str.size(); j++) { //*�� 0���ں��� �ѱ��ھ� �÷����� �� ���ڸ� �����ϴ��� ã�ƺ���
            if (func(w + 1, s + j))
                return ret = 1;
        }
    }
    //�ᱹ �ϳ��� ���� �ʰ� �� ��
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
        sort(word.begin(), word.end(), less<string>()); //�������� ����
        for (int j = 0; j < word.size(); j++)
            cout << word[j] << endl;
        //�� �׽�Ʈ ���̽��� ������ �ʱ�ȭ
        wc.clear();
        str.clear();
        word.clear();
    }
    return 0;
}