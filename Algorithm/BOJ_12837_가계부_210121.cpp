#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long LL;

vector<int> v;
vector<LL> segmentTree;
int N, M;

LL update_tree(int Node, int Start, int End, int Index, LL value) {
	if (Index < Start || End < Index) { return segmentTree[Node]; }
	if (Start == End) { return segmentTree[Node] += value; }
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = (update_tree(Node * 2, Start, Mid, Index, value) + update_tree(Node * 2 + 1, Mid + 1, End, Index, value));
}

LL sum_tree(int Node, int Start, int End, int Left, int Right) {
	if (Right < Start || End < Left) { return 0; }
	if (Left <= Start && End <= Right) { return segmentTree[Node]; }
	int Mid = (Start + End) / 2;
	return sum_tree(Node * 2, Start, Mid, Left, Right) + sum_tree(Node * 2 + 1, Mid + 1, End, Left, Right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int treeHeight = (int)ceil(log2(N));
	int treeSize = (1 << (treeHeight + 1));
	v.assign(N, 0);
	segmentTree.assign(treeSize, 0);
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			update_tree(1, 0, N - 1, b - 1, c);
		}
		else
		{
			if (c < b)
			{
				swap(b, c);
			}
			cout << sum_tree(1, 0, N - 1, b - 1, c - 1) << "\n";
		}
	}
	return 0;
}