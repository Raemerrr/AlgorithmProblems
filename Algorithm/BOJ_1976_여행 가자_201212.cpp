#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
map<int, int> parent;
map<int, int> parentRank;
vector<vector<int>> board;
vector<int> order;

//find
int findParent(int key) {
	if (parent[key] == key)
	{
		return key;
	}
	return parent[key] = findParent(parent[key]);
}

//union
void merge(int A, int B) {
	int p1 = findParent(A);
	int p2 = findParent(B);

	if (p1 == p2)
	{
		return;
	}

	if (parentRank[p1] < parentRank[p2])
	{
		swap(p1, p2);
	}

	parent[p2] = p1;
	parentRank[p1] += parentRank[p2];
	parentRank[p2] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	board = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	order = vector<int>(M, 0);
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
		parentRank[i] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> order[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			//������ �Ǿ� ���ִ�, �� �ڽ��� �ƴϴ�, ����� ���� ���� �ӿ� ���� �ʴ�.
			if (board[i][j] == 1 && i != j && findParent(i) != findParent(j))
			{
				//������ó��
				merge(i, j);
			}
		}
	}
	//���� �θ� ù order�� �θ�� ��´�.
	int flag = findParent(order[0]);
	for (int i = 1; i < order.size(); i++)
	{
		//�θ� �ٸ����� �ִٸ� �Ұ���
		if (flag != findParent(order[i]))
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}