#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 10000000;
int N, M, start = 1;
//현재 노드에서 연결된 다음 노드와 비용
vector<vector<pair<int, int>>> v;
//최적의 비용, 이전 노드 번호
vector<pair<int, int>> dist;
vector<pair<int, int>> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
	//가장 큰 값으로 초기화
	dist = vector<pair<int, int>>(N + 1, pair<int, int>(INF, 0));
	for (int i = 0; i < M; i++)
	{
		int num1 = 0, num2 = 0, cost = 0;
		cin >> num1 >> num2 >> cost;
		v[num1].emplace_back(num2, cost);
		v[num2].emplace_back(num1, cost);
	}

	priority_queue<pair<int, int>> pq;
	//시작은 1번 수퍼컴퓨터 부터
	pq.emplace(0, start);
	//시작 거리는 0으로 시작
	dist[start].first = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			int Next = v[cur][i].first;
			int nCost = v[cur][i].second;
			//가장 최적의 비용으로 방문했다면
			if (dist[Next].first > cost + nCost)
			{
				//최적의 비용 저장
				dist[Next].first = cost + nCost;
				//이전 방문 노드 저장
				dist[Next].second = cur;
				pq.emplace(-dist[Next].first, Next);
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		//접근 할 수 없는 컴퓨터는 제외
		if (dist[i].first != INF)
		{
			ans.emplace_back(i, dist[i].second);
		}
	}
	cout << ans.size() << "\n";
	for (const auto& d : ans)
	{
		cout << d.first << " " << d.second << "\n";
	}
	return 0;
}