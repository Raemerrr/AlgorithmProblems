#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int N;
vector<int> v;
vector<int> segmentTree;
map<int, int> m;

int update_tree(int Node, int Start, int End, int Index, int value) {
	if (Index < Start || End < Index) { return segmentTree[Node]; }
	if (Start == End) { return segmentTree[Node] = value; }
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = update_tree(Node * 2, Start, Mid, Index, value) + update_tree(Node * 2 + 1, Mid + 1, End, Index, value);
}

int query_tree(int Node, int Start, int End, int Left, int Right) {
	if (Right < Start || End < Left) { return 0; }
	if (Left <= Start && End <= Right) { return segmentTree[Node]; }
	int Mid = (Start + End) / 2;
	return query_tree(Node * 2, Start, Mid, Left, Right) + query_tree(Node * 2 + 1, Mid + 1, End, Left, Right);
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
	vector<int> tempV = v;
	sort(tempV.rbegin(), tempV.rend());
	for (int i = 0; i < tempV.size(); i++)
	{
		m[tempV[i]] = i;
	}
	for (const auto& d : v) {
		update_tree(1, 0, N - 1, m[d], 1);
		cout << query_tree(1, 0, N - 1, 0, m[d]) << "\n";
	}
	return 0;
}