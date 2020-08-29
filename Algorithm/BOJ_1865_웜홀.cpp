#include <iostream>
#include <vector>

using namespace std;

const int INF = 100000000;
int N, M, W;
vector<vector<pair<int, int>>> v;
vector<int> dist;

void bellmanFord() 
{
	bool flag = false;
	for (int k = 1; k <= N; k++)
	{
		for (int cur = 1; cur <= N; cur++)
		{
			int cost = dist[cur];
			for (int j = 0; j < v[cur].size(); j++)
			{
				int Next = v[cur][j].first;
				int nCost = v[cur][j].second;
				//-------------�ٽ�-------------
				//���� ��Ŭ ���θ� �Ǵ� �ϱ�����
				//cost != INF ������ �ʴ´�.
				//if (cost != INF && dist[Next] > cost + nCost) -- Ʋ��
				if (dist[Next] > cost + nCost)
				{
					dist[Next] = cost + nCost;
					//���� ��Ŭ�� �̷����
					if (k == N) { flag = true; }
				}
			}
		}
	}
	//���� ����Ŭ ����O
	if (flag)
	{
		cout << "YES\n";
	}
	//���� ����Ŭ ����X
	else
	{
		cout << "NO\n";
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		cin >> N >> M >> W;
		v = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
		dist = vector<int>(N + 1, INF);
		dist[1] = 0;
		int num1 = 0, num2 = 0, cost = 0;
		//���� ���� (����� ����)
		for (int i = 0; i < M; i++)
		{
			cin >> num1 >> num2 >> cost;
			v[num1].emplace_back(num2, cost);
			v[num2].emplace_back(num1, cost);
		}
		//��Ȧ ���� (�ܹ��� ����)
		for (int i = 0; i < W; i++)
		{
			cin >> num1 >> num2 >> cost;
			v[num1].emplace_back(num2, -cost);
		}
		//Bellman-Ford
		bellmanFord();
	}
	return 0;
}