#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;
int N, M, K;
vector<LL> v;
vector<LL> segmentTree;
vector<LL> lazyTree;

LL make_tree(int Node, int Start, int End) {
	if (Start == End) { return segmentTree[Node] = v[Start]; }
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = make_tree(Node * 2, Start, Mid) + make_tree(Node * 2 + 1, Mid + 1, End);
}

//lazy Update
void lazy_update(int Node, int Start, int End) {
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

LL update_tree(int Node, int Start, int End, int Left, int Right, LL value) {
	lazy_update(Node, Start, End);
	if (Right < Start || End < Left) { return segmentTree[Node]; }
	if (Left <= Start && End <= Right)
	{
		segmentTree[Node] += (End - Start + 1) * value;
		if (Start != End)
		{
			lazyTree[Node * 2] += value;
			lazyTree[Node * 2 + 1] += value;
		}
		return segmentTree[Node];
	}
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = update_tree(Node * 2, Start, Mid, Left, Right, value) + update_tree(Node * 2 + 1, Mid + 1, End, Left, Right, value);
}

LL sum_tree(int Node, int Start, int End, int Left, int Right) {
	lazy_update(Node, Start, End); //기존 sum방법에서 추가
	if (End < Left || Right < Start) { return 0; }
	if (Left <= Start && End <= Right) { return segmentTree[Node]; }
	int Mid = (Start + End) / 2;
	return sum_tree(Node * 2, Start, Mid, Left, Right) + sum_tree(Node * 2 + 1, Mid + 1, End, Left, Right);
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
		if (a == 1)
		{
			cin >> d;
			update_tree(1, 0, N - 1, b - 1, c - 1, d);
		}
		else
		{
			cout << sum_tree(1, 0, N - 1, b - 1, c - 1) << "\n";
		}
	}
	return 0;
}