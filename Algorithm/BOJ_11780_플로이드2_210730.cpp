#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;

const int INF = 100000;
int N, M;
vector<vector<pair<int, int>>> nodes;
vector<vector<pair<LL, vector<int>>>> dists;

void dijkstra(const int Start) {
	priority_queue<pair<int, int>> pq;
	vector<pair<LL, vector<int>>> dist(N, pair<LL, vector<int>>(INF, vector<int>()));;
	dist[Start].first = 0;
	dist[Start].second.push_back(Start);
	pq.emplace(0, Start);
	while (!pq.empty())
	{
		int Cost = -pq.top().first;
		int Cur = pq.top().second;
		pq.pop();
		for (const pair<int, int>& d : nodes[Cur]) {
			int Next = d.first;
			int nCost = d.second;

			if (dist[Next].first >= Cost + nCost)
			{
				vector<int> temp = dist[Cur].second;
				temp.push_back(Next);
				if (dist[Next].first == Cost + nCost)
				{
					dist[Next].second = (dist[Next].second <= temp) ? dist[Next].second : temp;
				}
				else
				{
					dist[Next].second = temp;
					dist[Next].first = Cost + nCost;
					pq.emplace(-dist[Next].first, Next);
				}
			}
		}
	}
	dists[Start] = dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	nodes.assign(N, vector<pair<int, int>>());
	dists.assign(N, vector<pair<LL, vector<int>>>());
	for (int i = 0; i < M; i++)
	{
		int a = 0, b = 0, c = 0; cin >> a >> b >> c; a--, b--;
		// 단방향 연결 주의
		nodes[a].emplace_back(b, c);
	}
	for (int i = 0; i < N; i++)
	{
		dijkstra(i);
	}
	for (const vector<pair<LL, vector<int>>>& d : dists)
	{
		for (const pair<LL, vector<int>>& z : d) {
			cout << ((z.first != INF) ? z.first : 0) << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < dists.size(); i++)
	{
		for (int j = 0; j < dists[i].size(); j++)
		{
			if (i == j) cout << "0\n";
			else {
				cout << ((dists[i][j].first != INF) ? dists[i][j].second.size() : 0) << " ";
				for (const int d : dists[i][j].second) {
					cout << d + 1 << " ";
				}
				cout << "\n";
			}
		}
	}
	return 0;
}