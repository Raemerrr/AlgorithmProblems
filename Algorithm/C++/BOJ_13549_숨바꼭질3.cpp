#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100000 + 1;
int A, B;
vector<int> dist;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	dist = vector<int>(MAX, MAX);
	cin >> A >> B;

	priority_queue<pair<int, int>> pq;
	pq.emplace(0, A);
	dist[A] = 0;
	while (!pq.empty())
	{
		//최소 힙 음수 전환 -
		int cost = -pq.top().first;
		int cur = pq.top().second;
		if (cur == B)
		{
			break;
		}
		pq.pop();
		// * 2 
		if (cur * 2 < MAX && dist[cur * 2] > cost)
		{
			dist[cur * 2] = cost;
			//최소 힙 음수 전환 -
			pq.emplace(-dist[cur * 2], cur * 2);
		}
		// + 1
		if (cur + 1 < MAX && dist[cur + 1] > cost + 1)
		{
			dist[cur + 1] = cost + 1;
			//최소 힙 음수 전환 -
			pq.emplace(-dist[cur + 1], cur + 1);
		}
		// - 1
		if (cur - 1 >= 0 && dist[cur - 1] > cost + 1)
		{
			dist[cur - 1] = cost + 1;
			//최소 힙 음수 전환 -
			pq.emplace(-dist[cur - 1], cur - 1);
		}
	}
	cout << dist[B] << "\n";
	return 0;
}