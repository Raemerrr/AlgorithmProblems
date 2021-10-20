#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<int> v{ 1,2,3,4 };
vector<int> segmentTree;
vector<int> minSegmentTree;

int makeSegmentTree(int node, int _start, int _end) {
	if (_start == _end) { return segmentTree[node] = v[_start]; }
	int _mid = (_start + _end) / 2;
	int leftResult = makeSegmentTree(node * 2, _start, _mid);
	int rightResult = makeSegmentTree(node * 2 + 1, _mid + 1, _end);
	return segmentTree[node] = leftResult + rightResult;
}

int makeMinSegmentTree(int Node, int Start, int End) {
	if (Start == End) { return minSegmentTree[Node] = v[Start]; }
	int Mid = (Start + End) / 2;
	int leftResult = makeMinSegmentTree(Node * 2, Start, Mid);
	int rightResult = makeMinSegmentTree(Node * 2 + 1, Mid + 1, End);
	return minSegmentTree[Node] = min(leftResult, rightResult);
}

int sumSegementTree(int node, int _start, int _end, int _left, int _right) {
	if (_left > _end || _right < _start) { return 0; }
	if (_start >= _left && _right >= _end) { return segmentTree[node]; }

	int _mid = (_start + _end) / 2;
	int leftResult = sumSegementTree(node * 2, _start, _mid, _left, _right);
	int rightResult = sumSegementTree(node * 2 + 1, _mid + 1, _end, _left, _right);
	return leftResult + rightResult;
}

void updateSegmentTree(int node, int _start, int _end, int index, int _diff) {
	if (index < _start || _end < index) { return; };
	segmentTree[node] += _diff;

	if (_start != _end)
	{
		int _mid = (_start + _end) / 2;
		updateSegmentTree(node * 2, _start, _mid, index, _diff);
		updateSegmentTree(node * 2 + 1, _mid + 1, _end, index, _diff);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	N = v.size();
	int treeHeigt = (int)ceil(log2(N));
	int treeSize = (1 << (treeHeigt + 1));
	segmentTree.assign(treeSize, 0);
	minSegmentTree.assign(treeSize, 0);
	makeSegmentTree(1, 0, N - 1);
	makeMinSegmentTree(1, 0, N - 1);
	cout << "sum : " << sumSegementTree(1, 0, N - 1, 0, 1) << "\n";

	int updateTarget = 1;
	int changeValue = 8;
	int _diff = 2;
	updateSegmentTree(1, 0, N - 1, updateTarget, _diff);
	cout << "sum : " << sumSegementTree(1, 0, N - 1, 0, 1) << "\n";
	return 0;
}