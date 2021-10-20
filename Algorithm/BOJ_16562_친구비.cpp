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
	//*주의 '친구비'가 작은 쪽으로 합
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
	//'친구비'로 초기화
	for (int i = 1; i <= N; i++)
	{
		int cost = 0;
		cin >> cost;
		parentRank[i] = cost;
		parent[i] = i;
	}
	//친구관계가 형성되어있는 친구는 합
	for (int i = 0; i < M; i++)
	{
		int v = 0, w = 0;
		cin >> v >> w;
		merge(v, w);
	}
	//각 친구들의 합집합 루트 노드의 비용만 '친구비'로 지불
	for (int i = 1; i <= N; i++)
	{
		int p = findParent(i);
		if (!check.count(p))
		{
			check[p] = true;
			k -= parentRank[p];
			answer += parentRank[p];
			//가진 비용보다 '친구비'가 크면 종료
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