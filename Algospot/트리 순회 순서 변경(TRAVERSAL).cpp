/*
문제 -트리 순회 순서 변경(TRAVERSAL)(https://algospot.com/judge/problem/read/TRAVERSAL)

풀이
	전위 순회의 첫번째 순서는 반드시 해당 트리의 루트이므로 중위 순위에서 루트가 어디있는지를 알면 각각의 서브트리를 알 수 있다.
	따라서 후위 순회 순서는 각 서브트리를 탐색하고 이후에 루트를 출력하면 된다.
	이를 재귀적으로 표현하면 된다.
*/


#include <iostream>
#include <vector>

using namespace std;

vector<int> cut(const vector<int>& v, int a, int b) {	//a부터 b까지 배열을 잘라내는 함수
	return vector<int>(v.begin() + a, v.begin() + b);
}

void postOrder(const vector<int>& pre, const vector<int>& in) {	//후위 우선 순회로 출력하는 함수
	if (pre.empty())	//비어있으면 바로 반환
		return;

	int root = pre[0];	//전위 순회의 처음은 반드시 루트
	int inLeft = 0;
	for (int i = 0; i < in.size(); i++) {	//각 서브트리가 나눠지는 위치
		if (in[i] == root) {
			inLeft = i;
			break;
		}
	}

	postOrder(cut(pre, 1, inLeft + 1), cut(in, 0, inLeft));	//첫번째 서브 트리의 전위, 중위 순회
	postOrder(cut(pre, inLeft + 1, pre.size()), cut(in, inLeft + 1, in.size()));	//두번쨰 서브트리의 전위, 중위 순회
	cout << root << ' ';
}

int main() {
	int c, n, tmp;
	cin >> c;
	vector<int> pre;
	vector<int> in;
	for (int i = 0; i < c; i++) {
		pre.clear();
		in.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			pre.push_back(tmp);
		}for (int i = 0; i < n; i++) {
			cin >> tmp;
			in.push_back(tmp);
		}

		postOrder(pre, in);
		cout << endl;

	}
	return 0;
}