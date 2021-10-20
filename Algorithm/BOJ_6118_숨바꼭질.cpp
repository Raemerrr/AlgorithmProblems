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
		//����� ����
		v[num1].emplace_back(num2, 1);
		v[num2].emplace_back(num1, 1);
	}
	//�켱 ���� ť�� �̿��� ���ͽ�Ʈ��
	priority_queue<pair<int, int>> PQ;
	PQ.emplace(0, start);
	//������ 0���� �ʱ�ȭ
	dist[start] = 0;
	while (!PQ.empty())
	{
		// - ���� ��ȣ ��ȯ (�ּ� ��)
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
				// - ���� ��ȣ ��ȯ (�ּ� ��)
				PQ.emplace(-dist[Next], Next);
			}
		}
	}

	//���� ����
	for (int i = 1; i <= N; i++)
	{
		int curDist = dist[i];
		m[curDist].emplace_back(i);
	}
	//�������� ����
	sort((*m.begin()).second.begin(), (*m.begin()).second.end());
	cout << (*m.begin()).second[0] << " " << (*m.begin()).first << " " << (*m.begin()).second.size() << "\n";
	return 0;
}