#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

const int MOD = 1000000007;
int N, M, K;
vector<ULL> v, segmentTree;

ULL make_tree(int Node, int Start, int End) {
	if (Start == End) return segmentTree[Node] = v[Start] % MOD;
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = (make_tree(Node * 2, Start, Mid) * make_tree(Node * 2 + 1, Mid + 1, End) % MOD);
}

ULL update_tree(int Node, int Start, int End, int Index, ULL Value) {
	if (Index < Start || End < Index) return segmentTree[Node];
	if (Start == End) return segmentTree[Node] = Value;
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = (update_tree(Node * 2, Start, Mid, Index, Value) * update_tree(Node * 2 + 1, Mid + 1, End, Index, Value) % MOD);
}

ULL query_tree(int Node, int Start, int End, int Left, int Right) {
	if (Right < Start || End < Left) return 1;
	if (Left <= Start && End <= Right) return segmentTree[Node];
	int Mid = (Start + End) / 2;
	return (query_tree(Node * 2, Start, Mid, Left, Right) * query_tree(Node * 2 + 1, Mid + 1, End, Left, Right) % MOD);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	v.assign(N, 0);
	int treeHeight = (int)ceil(log2(N));
	int treeSize = (1 << (treeHeight + 1));
	for (int i = 0; i < N; i++) cin >> v[i];
	segmentTree.assign(treeSize, 0);
	make_tree(1, 0, N - 1);
	for (int i = 0; i < M + K; i++)
	{
		int a = 0, b = 0; ULL c = 0; cin >> a >> b >> c;
		if (a == 1)
			update_tree(1, 0, N - 1, b - 1, c);
		else
			cout << query_tree(1, 0, N - 1, b - 1, c - 1) << "\n";
	}
	return 0;
}