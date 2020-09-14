#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10;
vector<int> parent;

//부모 노드 찾기
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
	parent = vector<int>(MAX, 0);
	for (int i = 0; i < MAX; i++)
	{
		parent[i] = i;
	}

	if (findParent(0, 1))
	{
		cout << "같은 부모\n";
	}
	else
	{
		cout << "다른 부모\n";
	}
	//부모 합치기!
	unionParent(0, 1);

	if (findParent(0, 1))
	{
		cout << "같은 부모\n";
	}
	else
	{
		cout << "다른 부모\n";
	}
	return 0;
}