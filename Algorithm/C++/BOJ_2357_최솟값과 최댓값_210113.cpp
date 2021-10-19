#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 2000000000;
const int MIN = 0;
int N, M;
vector<int> v;
vector<int> minTree;
vector<int> maxTree;

int makeMinTree(int Node, int Start, int End) {
	if (Start == End) { return minTree[Node] = v[Start]; }
	int Mid = (Start + End) / 2;
	int leftResult = makeMinTree(Node * 2, Start, Mid);
	int rightResult = makeMinTree(Node * 2 + 1, Mid + 1, End);
	return minTree[Node] = min(leftResult, rightResult);
}

int makeMaxTree(int Node, int Start, int End) {
	if (Start == End) { return maxTree[Node] = v[Start]; }
	int Mid = (Start + End) / 2;
	int leftResult = makeMaxTree(Node * 2, Start, Mid);
	int rightResult = makeMaxTree(Node * 2 + 1, Mid + 1, End);
	return maxTree[Node] = max(leftResult, rightResult);
}

int searchMinTree(int Node, int Start, int End, int Left, int Right) {
	if (Left > End || Right < Start) { return MAX; }
	if (Left <= Start && End <= Right) { return minTree[Node]; }
	int Mid = (Start + End) / 2;
	int LeftResult = searchMinTree(Node * 2, Start, Mid, Left, Right);
	int RightResult = searchMinTree(Node * 2 + 1, Mid + 1, End, Left, Right);
	return min(LeftResult, RightResult);
}

int searchMaxTree(int Node, int Start, int End, int Left, int Right) {
	if (Left > End || Right < Start) { return MIN; }
	if (Left <= Start && End <= Right) { return maxTree[Node]; }
	int Mid = (Start + End) / 2;
	int LeftResult = searchMaxTree(Node * 2, Start, Mid, Left, Right);
	int RightResult = searchMaxTree(Node * 2 + 1, Mid + 1, End, Left, Right);
	return max(LeftResult, RightResult);
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
	minTree.assign(treeSize, 0);
	maxTree.assign(treeSize, 0);
	makeMinTree(1, 0, N - 1);
	makeMaxTree(1, 0, N - 1);
	int a = 0, b = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		cout << searchMinTree(1, 0, N - 1, a - 1, b - 1) << " ";
		cout << searchMaxTree(1, 0, N - 1, a - 1, b - 1) << "\n";
	}
	return 0;
}