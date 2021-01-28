#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int N, M;
map<int, int> idx;
vector<int> segmentTree;
vector<int> answer;

int query_tree(int Node, int Start, int End, int Left, int Right) {
	if (Right < Start || End < Left) { return 0; }
	if (Left <= Start && End <= Right) { return segmentTree[Node]; }
	int Mid = (Start + End) / 2;
	return query_tree(Node * 2, Start, Mid, Left, Right) + query_tree(Node * 2 + 1, Mid + 1, End, Left, Right);
}

int update_tree(int Node, int Start, int End, int Index, int value) {
	if (Index < Start || End < Index) { return segmentTree[Node]; }
	if (Start == End) { return segmentTree[Node] = value; }
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = update_tree(Node * 2, Start, Mid, Index, value) + update_tree(Node * 2 + 1, Mid + 1, End, Index, value);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	while (test_case--)
	{
		cin >> N >> M;
		idx.clear();
		int treeHeight = (int)ceil(log2(N + M));
		int treeSize = (1 << (treeHeight + 1));
		segmentTree.assign(treeSize, 0);
		answer.assign(M, 0);
		int num = 0;
		for (int i = M; i < N + M; i++)
		{
			update_tree(1, 0, N + M - 1, i, 1);
			idx[i - M + 1] = i;
		}
		for (int i = 0; i < M; i++)
		{
			cin >> num;
			answer[i] = query_tree(1, 0, N + M - 1, 0, idx[num] - 1);
			update_tree(1, 0, N + M - 1, idx[num], 0);
			idx[num] = M - 1 - i;
			update_tree(1, 0, N + M - 1, idx[num], 1);
		}
		for (const auto& d : answer) { cout << d << " "; }
		cout << "\n";
	}

	return 0;
}