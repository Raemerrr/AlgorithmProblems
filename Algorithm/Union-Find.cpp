#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//�θ� ��� ã��
int getParent(const int n)
{
	if (parent[n] == n) { return n; }
	return parent[n] = getParent(parent[n]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b)
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
	}
}

bool findParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 10; i++)
	{
		parent.push_back(i);
	}

	if (findParent(0, 1))
	{
		cout << "���� �θ�\n";
	}
	else
	{
		cout << "�ٸ� �θ�\n";
	}
	//�θ� ��ġ��!
	unionParent(0, 1);

	if (findParent(0, 1))
	{
		cout << "���� �θ�\n";
	}
	else
	{
		cout << "�ٸ� �θ�\n";
	}
	return 0;
}