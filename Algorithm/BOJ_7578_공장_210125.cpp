#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;
typedef long long LL;

int N;
LL answer;
vector<LL> v;
vector<LL> segmentTree;
map<int, int> idx;

LL update_tree(int Node, int Start, int End, int Index, int value) {
	if (Index < Start || End < Index) { return segmentTree[Node]; }
	if (Start == End) { return segmentTree[Node] = value; }
	int Mid = (Start + End) / 2;
	return segmentTree[Node] = (update_tree(Node * 2, Start, Mid, Index, value) + update_tree(Node * 2 + 1, Mid + 1, End, Index, value));
}

LL query_tree(int Node, int Start, int End, int Left, int Right) {
	if (End < Left || Right < Start) { return 0; }
	if (Left <= Start && End <= Right) { return segmentTree[Node]; }
	int Mid = (Start + End) / 2;
	return (query_tree(Node * 2, Start, Mid, Left, Right) + query_tree(Node * 2 + 1, Mid + 1, End, Left, Right));
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int treeHeight = (int)ceil(log2(N));
	int treeSize = (1 << (treeHeight + 1));
	segmentTree.assign(treeSize, 0);
	int num = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		idx[num] = i;
	}
	v.assign(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v[i] = idx[num];
	}
	reverse(v.begin(),v.end());
	for (int i = 0; i < N; i++)
	{
		int Index = v[i];
		answer += query_tree(1, 0, N - 1, 0, Index);
		update_tree(1, 0, N - 1, Index, 1);
	}
	cout << answer << "\n";
	return 0;
}