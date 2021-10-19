#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;
int N, Q;
vector<LL> v;
vector<LL> segmentTree;

LL make_tree(int Node, int Start, int End) {
	if (Start == End) { return segmentTree[Node] = v[Start]; }
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = (make_tree(Node * 2, Start, Mid) + make_tree(Node * 2 + 1, Mid + 1, End));
}

LL update_tree(int Node, int Start, int End, int Index, LL value) {

	if (Index < Start || End < Index) { return segmentTree[Node]; }
	if (Start == End) {	return segmentTree[Node] = value; }
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = (update_tree(Node * 2, Start, Mid, Index, value) + update_tree(Node * 2 + 1, Mid + 1, End, Index, value));
}

LL query_tree(int Node, int Start, int End, int Left, int Right) {
	if (End < Left || Right < Start) { return 0; }
	if (Left <= Start && End <= Right) { return segmentTree[Node]; }
	int Mid = (Start + End) / 2;
	return (query_tree(Node * 2, Start, Mid, Left, Right) + query_tree(Node * 2 + 1, Mid + 1, End, Left, Right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> Q;
	v.assign(N, 0);
	int treeHeight = (int)ceil(log2(N));
	int treeSize = (1 << (treeHeight + 1));
	segmentTree.assign(treeSize, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	make_tree(1, 0, N - 1);
	int x = 0, y = 0, a = 0, b = 0;
	for (int i = 0; i < Q; i++)
	{
		cin >> x >> y >> a >> b;
		if (x > y)
		{
			swap(x, y);
		}
		cout << query_tree(1, 0, N - 1, x - 1, y - 1) << "\n";
		update_tree(1, 0, N - 1, a - 1, b);
	}
	return 0;
}