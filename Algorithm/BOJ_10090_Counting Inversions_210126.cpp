#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;
int N;
vector<pair<int, int>> v;
vector<LL> segmentTree;
LL answer;

LL update_tree(int Node, int Start, int End, int Index, LL value) {
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
	v.assign(N, { 0,0 });
	segmentTree.assign(treeSize, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first;
		// {-4,-1}, {-2,-2} .. 숫자가 큰 수를 앞으로 배치하기 위해 음수 전환
		// {-4,-1}, {-4,-2} .. 같은 숫자가 나온다면 뒤에 나온 숫자를 더 앞으로 보냄.
		v[i].first *= -1; v[i].second = -(i + 1);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
	{
		int idx = (v[i].second * -1) - 1;
		answer += query_tree(1, 0, N - 1, 0, idx);
		update_tree(1, 0, N - 1, idx, 1);
	}
	cout << answer << "\n";
	return 0;
}