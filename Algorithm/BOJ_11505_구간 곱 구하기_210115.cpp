#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

const int MOD = 1000000007;
int N, M, K;
vector<ULL> v;
vector<ULL> segment;

ULL make_tree(int Node, int Start, int End) {
	if (Start == End) { return segment[Node] = v[Start] % MOD; }
	int Mid = (Start + End) / 2;
	return segment[Node] = (make_tree(Node * 2, Start, Mid) * make_tree(Node * 2 + 1, Mid + 1, End) % MOD);
}

ULL update_tree(int Node, int Start, int End, int Index, ULL value) {
	//내가 구하고자 하는 구간 밖이라면 기존 값을 넘겨준다.
	if (Index < Start || End < Index) { return segment[Node]; }
	//leaf노드라면 값 입력 즉, 변경된 값이 입력될 것이다..(?)
	if (Start == End) { return segment[Node] = value; }

	int Mid = (Start + End) / 2;
	return segment[Node] = (update_tree(Node * 2, Start, Mid, Index, value) * update_tree(Node * 2 + 1, Mid + 1, End, Index, value)) % MOD;
}

ULL query_tree(int Node, int Start, int End, int Left, int Right) {
	if (End < Left || Right < Start) { return 1; }
	if (Left <= Start && End <= Right) {
		return segment[Node];
	}
	int Mid = (Start + End) / 2;
	return (query_tree(Node * 2, Start, Mid, Left, Right) * query_tree(Node * 2 + 1, Mid + 1, End, Left, Right)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	v.assign(N, 0);
	int treeHeight = (int)ceil(log2(N));
	int treeSize = (1 << (treeHeight + 1));
	segment.assign(treeSize, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	make_tree(1, 0, N - 1);
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		//update
		if (a == 1)
		{
			v[b - 1] = c;
			update_tree(1, 0, N - 1, b - 1, c);
		}
		else
		{
			cout << query_tree(1, 0, N - 1, b - 1, c - 1) << "\n";
		}
	}
	return 0;
}