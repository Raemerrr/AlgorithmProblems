#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

int N;
vector<int> v;
vector<LL> segmentTree;

LL make_tree(int Node, int Start, int End) {
	if (Start == End) { return segmentTree[Node] = v[Start]; }
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = min(make_tree(Node * 2, Start, Mid), make_tree(Node * 2 + 1, Mid + 1, End)) * 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v.assign(N, 0);
	int treeHeight = (int)ceil(log2(N));
	int treeSize = (1 << (treeHeight + 1));
	segmentTree.assign(treeSize, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	make_tree(1, 0, N - 1);
	cout << segmentTree[1] << "\n";
	return 0;
}