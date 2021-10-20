#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> parent;
map<int, int> parentRank;
int N, M;

//�θ� ��� ã��
int findParent(int key) {
	if (parent[key] == key)
	{
		return key;
	}
	return parent[key] = findParent(parent[key]);
}

//������ �����
void merge(int num1, int num2) {
	int p1 = findParent(num1);
	int p2 = findParent(num2);

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
	//ù �Է��� �ڱ� �ڽ��� �θ�� �ϸ�, �� Ʈ���� Rank�� 1 �Է�
	for (int i = 0; i < N + 1; i++)
	{
		parent[i] = i;
		parentRank[i] = 1;
	}
	
	for (int i = 0; i < M; i++)
	{
		int flag = 0, num1 = 0, num2 = 0;
		cin >> flag >> num1 >> num2;
		//merge
		if (!flag)
		{
			merge(num1, num2);
		}
		//���� �������� Ȯ��
		else
		{
			cout << ((findParent(num1) == findParent(num2)) ? "YES\n" : "NO\n");
		}
	}
	return 0;
}