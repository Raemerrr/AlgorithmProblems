#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M, K;
vector<long long> v;
vector<long long> segmentTree;

long long make_tree(int Node, int Start, int End) {
	if (Start == End) { return segmentTree[Node] = v[Start]; }
	int Mid = (Start + End) / 2;
	long long Left = make_tree(Node * 2, Start, Mid);
	long long Right = make_tree(Node * 2 + 1, Mid + 1, End);
	return segmentTree[Node] = Left + Right;
}

long long sum_tree(int Node, int Start, int End, int Left, int Right) {
	if (End < Left || Right < Start) { return 0; }
	if (Left <= Start && End <= Right) { return segmentTree[Node]; }
	int Mid = (Start + End) / 2;
	long long LeftResult = sum_tree(Node * 2, Start, Mid, Left, Right);
	long long RightResult = sum_tree(Node * 2 + 1, Mid + 1, End, Left, Right);
	return LeftResult + RightResult;
}

void update_tree(int Node, int Start, int End, int index, int Diff) {
	if (index < Start || End < index) { return; }
	segmentTree[Node] += Diff;
	if (Start != End)
	{
		int Mid = (Start + End) / 2;
		update_tree(Node * 2, Start, Mid, index, Diff);
		update_tree(Node * 2 + 1, Mid + 1, End, index, Diff);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	v.assign(N, 0);
	int treeHeight = (int)ceil(log2(N));
	int treeSize = (1 << (treeHeight + 1));
	segmentTree.assign(treeSize, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	make_tree(1, 0, N - 1);
	long long a = 0, b = 0, c = 0;
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		//update
		if (a == 1)
		{
			b--;
			long long Diff = c - v[b];
			v[b] = c;
			update_tree(1, 0, N - 1, b, Diff);
		}
		//sum
		else
		{
			b--; c--;
			cout << sum_tree(1, 0, N - 1, b, c) << "\n";
		}
	}
	return 0;
}