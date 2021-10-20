#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> parent;
map<int, int> parentRank;
int N, M;

//부모 노드 찾기
int findParent(int key) {
	if (parent[key] == key)
	{
		return key;
	}
	return parent[key] = findParent(parent[key]);
}

//합집합 만들기
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
	//첫 입력은 자기 자신을 부모로 하며, 각 트리의 Rank는 1 입력
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
		//같은 집합인지 확인
		else
		{
			cout << ((findParent(num1) == findParent(num2)) ? "YES\n" : "NO\n");
		}
	}
	return 0;
}