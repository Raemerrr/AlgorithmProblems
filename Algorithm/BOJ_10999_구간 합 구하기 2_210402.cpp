#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;
int N, M, K;
vector<LL> segmentTree;
vector<LL> lazyTree;
vector<int> v;

LL make_tree(int Node, int Start, int End) {
	if (Start == End) { return segmentTree[Node] = v[Start]; }
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = (make_tree(Node * 2, Start, Mid) + make_tree(Node * 2 + 1, Mid + 1, End));
}

void Lazy_update(int Node, int Start, int End) {
	if (lazyTree[Node] != 0)
	{
		segmentTree[Node] += (End - Start + 1) * lazyTree[Node];
		if (Start != End)
		{
			lazyTree[Node * 2] += lazyTree[Node];
			lazyTree[Node * 2 + 1] += lazyTree[Node];
		}
		lazyTree[Node] = 0;
	}
}

LL update_tree(int Node, int Start, int End, int Left, int Right, LL Value)
{
	Lazy_update(Node, Start, End);
	if (End < Left || Right < Start) { return segmentTree[Node]; }
	if (Left <= Start && End <= Right)
	{
		segmentTree[Node] += (End - Start + 1) * Value;
		if (Start != End)
		{
			lazyTree[Node * 2] += Value;
			lazyTree[Node * 2 + 1] += Value;
		}
		return segmentTree[Node];
	}
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = update_tree(Node * 2, Start, Mid, Left, Right, Value) + update_tree(Node * 2 + 1, Mid + 1, End, Left, Right, Value);
}

LL query_tree(int Node, int Start, int End, int Left, int Right) {
	Lazy_update(Node, Start, End);
	if (End < Left || Right < Start) { return 0; }
	if (Left <= Start && End <= Right) { return segmentTree[Node]; }
	int Mid = (Start + End) / 2;
	return query_tree(Node * 2, Start, Mid, Left, Right) + query_tree(Node * 2 + 1, Mid + 1, End, Left, Right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	v.assign(N, 0);
	int treeHeight = (int)ceil(log2(N));
	int treeSize = (1 << (treeHeight + 1));
	segmentTree.assign(treeSize, 0);
	lazyTree.assign(treeSize, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	make_tree(1, 0, N - 1);
	int a = 0, b = 0, c = 0, d = 0;
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		//구간 업데이트
		if (a == 1)
		{
			cin >> d;
			update_tree(1, 0, N - 1, b - 1, c - 1, d);
		}
		//구간 합
		else
		{
			cout << query_tree(1, 0, N - 1, b - 1, c - 1) << "\n";
		}
	}
	return 0;
}