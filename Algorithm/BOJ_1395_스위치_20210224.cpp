#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
vector<int> segmentTree;
vector<int> lazyTree;

void lazy_update(int Node, int Start, int End) {
	if (lazyTree[Node] != 0)
	{
		segmentTree[Node] = (End - Start + 1) - segmentTree[Node];
		if (Start != End)
		{
			lazyTree[Node * 2] = !lazyTree[Node * 2];
			lazyTree[Node * 2 + 1] = !lazyTree[Node * 2 + 1];
		}
		lazyTree[Node] = 0;
	}
}

int update_tree(int Node, int Start, int End, int Left, int Right) {
	lazy_update(Node, Start, End);
	if (End < Left || Right < Start) { return segmentTree[Node]; }
	if (Left <= Start && End <= Right)
	{
		segmentTree[Node] = (End - Start + 1) - segmentTree[Node];
		if (Start != End)
		{
			lazyTree[Node * 2] = !lazyTree[Node * 2];
			lazyTree[Node * 2 + 1] = !lazyTree[Node * 2 + 1];
		}
		return segmentTree[Node];
	}
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = update_tree(Node * 2, Start, Mid, Left, Right) + update_tree(Node * 2 + 1, Mid + 1, End, Left, Right);
}

int query_tree(int Node, int Start, int End, int Left, int Right) {
	lazy_update(Node, Start, End);
	if (End < Left || Right < Start) { return 0; }
	if (Left <= Start && End <= Right) { return segmentTree[Node]; }
	int Mid = (Start + End) / 2;
	return query_tree(Node * 2, Start, Mid, Left, Right) + query_tree(Node * 2 + 1, Mid + 1, End, Left, Right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int treeHeight = (int)ceil(log2(N));
	int treeSize = (1 << (treeHeight + 1));
	segmentTree.assign(treeSize, 0);
	lazyTree.assign(treeSize, 0);
	int o = 0, s = 0, t = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> o >> s >> t;
		//update
		if (o == 0)
		{
			update_tree(1, 0, N - 1, s - 1, t - 1);
		}
		//query (sum)
		else
		{
			cout << query_tree(1, 0, N - 1, s - 1, t - 1) << "\n";
		}
	}
	return 0;
}