#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;
const int MAX = 1000000;
int N, treeSize;
LL ret;
vector<LL> segmentTree;
map<int, LL> values;

LL update_tree(int Node, int Start, int End, int Index, LL value) {
	if (Index < Start || End < Index) { return segmentTree[Node]; }
	if (Start == End) { return segmentTree[Node] = value; }
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = update_tree(Node * 2, Start, Mid, Index, value) + update_tree(Node * 2 + 1, Mid + 1, End, Index, value);
}

LL query_tree(int Node, int Start, int End, int k) {
	//Leaf Node
	if (ret == 0 && Start == End) { return Start; };
	int Mid = (Start + End) / 2;
	if (ret == 0 && Node * 2 < treeSize && segmentTree[Node * 2] >= k) {
		return ret = query_tree(Node * 2, Start, Mid, k);
	}
	k -= segmentTree[Node * 2];
	if (ret == 0 && Node * 2 + 1 < treeSize && segmentTree[Node * 2 + 1] >= k) {
		return ret = query_tree(Node * 2 + 1, Mid + 1, End, k);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int treeHeight = (int)ceil(log2(MAX));
	treeSize = (1 << (treeHeight + 1));
	segmentTree.assign(treeSize, 0);
	int a = 0, b = 0;
	LL c = 0;
	for (int i = 0; i < N; i++)
	{
		ret = 0;
		cin >> a >> b;
		if (a == 1) {
			//»©´Â°æ¿ì
			int idx = query_tree(1, 0, MAX - 1, b);
			cout << idx << "\n";
			values[idx]--;
			update_tree(1, 0, MAX - 1, idx, values[idx]);
		}
		else
		{
			cin >> c;
			//update
			values[b] += c;
			update_tree(1, 0, MAX - 1, b, values[b]);
		}
	}
	return 0;
}