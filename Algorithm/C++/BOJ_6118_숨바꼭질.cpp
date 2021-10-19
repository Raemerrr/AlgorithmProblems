#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 200000000;
vector<int> dist;
vector<vector<pair<int, int>>> v;
map<int, vector<int>, greater<int>> m;
int N, M, start = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
	dist = vector<int>(N + 1, INF);
	for (int i = 0; i < M; i++)
	{
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		//양방향 연결
		v[num1].emplace_back(num2, 1);
		v[num2].emplace_back(num1, 1);
	}
	//우선 순위 큐를 이용한 다익스트라
	priority_queue<pair<int, int>> PQ;
	PQ.emplace(0, start);
	//시작점 0으로 초기화
	dist[start] = 0;
	while (!PQ.empty())
	{
		// - 음수 기호 전환 (최소 힙)
		int cost = -PQ.top().first;
		int cur = PQ.top().second;
		PQ.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			int Next = v[cur][i].first;
			int nCost = v[cur][i].second;
			if (dist[Next] > cost + nCost)
			{
				dist[Next] = cost + nCost;
				// - 음수 기호 전환 (최소 힙)
				PQ.emplace(-dist[Next], Next);
			}
		}
	}

	//정답 도출
	for (int i = 1; i <= N; i++)
	{
		int curDist = dist[i];
		m[curDist].emplace_back(i);
	}
	//오름차순 정렬
	sort((*m.begin()).second.begin(), (*m.begin()).second.end());
	cout << (*m.begin()).second[0] << " " << (*m.begin()).first << " " << (*m.begin()).second.size() << "\n";
	return 0;
}