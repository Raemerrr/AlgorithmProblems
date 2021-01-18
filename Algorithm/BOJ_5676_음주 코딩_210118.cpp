#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
int N, K;
vector<int> v;
vector<int> segmentTree;

int converting(int val) {
	if (val == 0)
	{
		return 0;
	}
	else if (val > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int make_tree(int Node, int Start, int End) {
	if (Start == End) { return segmentTree[Node] = v[Start]; }
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = converting(make_tree(Node * 2, Start, Mid) * make_tree(Node * 2 + 1, Mid + 1, End));
}

int update_tree(int Node, int Start, int End, int Index, int value) {
	;
	if (Index < Start || End < Index) { return segmentTree[Node]; }
	if (Start == End) { return segmentTree[Node] = value; }
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = converting(update_tree(Node * 2, Start, Mid, Index, value) * update_tree(Node * 2 + 1, Mid + 1, End, Index, value));
}

int query_tree(int Node, int Start, int End, int Left, int Right) {
	if (End < Left || Right < Start)
	{
		return 1;
	}
	if (Left <= Start && End <= Right)
	{
		return segmentTree[Node];
	}
	int Mid = (Start + End) / 2;
	return converting(query_tree(Node * 2, Start, Mid, Left, Right) * query_tree(Node * 2 + 1, Mid + 1, End, Left, Right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	while (cin >> N >> K) {
		v.assign(N, 1);
		int treeHeight = (int)ceil(log2(N));
		int treeSize = (1 << (treeHeight + 1));
		segmentTree.assign(treeSize, 1);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}
		make_tree(1, 0, N - 1);
		char a = ' ';
		int b = 0, c = 0;
		for (int i = 0; i < K; i++)
		{
			cin >> a >> b >> c;
			//update
			if (a == 'C')
			{
				update_tree(1, 0, N - 1, b - 1, c);
			}
			else
			{
				int answer = query_tree(1, 0, N - 1, b - 1, c - 1);
				cout << (answer == 0 ? "0" : (answer > 0) ? "+" : "-");
			}
		}
		cout << "\n";
	}
	return 0;
}