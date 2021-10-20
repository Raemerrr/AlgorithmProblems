#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 1000000001;
int N, M;
vector<int> v;
vector<int> segmentTree;

int make_tree(int Node, int Start, int End) {
	if (Start == End)
	{
		return segmentTree[Node] = v[Start];
	}
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = min(make_tree(Node * 2, Start, Mid), make_tree(Node * 2 + 1, Mid + 1, End));
}

int search_tree(int Node, int Start, int End, int Left, int Right) {
	if (End < Left || Right < Start) { return MAX; }
	if (Left <= Start && End <= Right) { return segmentTree[Node]; }
	int Mid = (Start + End) / 2;
	return min(search_tree(Node * 2, Start, Mid, Left, Right), search_tree(Node * 2 + 1, Mid + 1, End, Left, Right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v.assign(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	int treeHeight = (int)ceil(log2(N));
	int treeSize = (1 << (treeHeight + 1));
	segmentTree.assign(treeSize, 0);
	make_tree(1, 0, N - 1);
	int a = 0, b = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		cout << search_tree(1, 0, N - 1, a - 1, b - 1) << "\n";;
	}
	return 0;
}