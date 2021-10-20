#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100001;
int N, M, k;
map<int, int> parentRank;
map<int, int> parent;
map<int, bool> check;
int answer;

int findParent(int key) {
	if (parent[key] == key)
	{
		return key;
	}
	return parent[key] = findParent(parent[key]);
}

void merge(int v, int w) {
	int p1 = findParent(v);
	int p2 = findParent(w);
	if (p1 == p2)
	{
		return;
	}
	//*���� 'ģ����'�� ���� ������ ��
	if (parentRank[p1] < parentRank[p2])
	{
		swap(p1, p2);
	}

	parent[p1] = p2;
	parentRank[p1] = MAX;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> k;
	//'ģ����'�� �ʱ�ȭ
	for (int i = 1; i <= N; i++)
	{
		int cost = 0;
		cin >> cost;
		parentRank[i] = cost;
		parent[i] = i;
	}
	//ģ�����谡 �����Ǿ��ִ� ģ���� ��
	for (int i = 0; i < M; i++)
	{
		int v = 0, w = 0;
		cin >> v >> w;
		merge(v, w);
	}
	//�� ģ������ ������ ��Ʈ ����� ��븸 'ģ����'�� ����
	for (int i = 1; i <= N; i++)
	{
		int p = findParent(i);
		if (!check.count(p))
		{
			check[p] = true;
			k -= parentRank[p];
			answer += parentRank[p];
			//���� ��뺸�� 'ģ����'�� ũ�� ����
			if (k < 0)
			{
				cout << "Oh no\n";
				return 0;
			}
		}
	}
	cout << answer << "\n";
	return 0;
}