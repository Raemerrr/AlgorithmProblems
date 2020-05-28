#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

int N, K, ans;

struct TopNi
{
	int dir;
	deque<int> dq;
	TopNi()
	{
		dir = 0;
		dq = deque<int>(8, 0);
	}
};

vector<TopNi> v;
vector<pair<int, int>> order;
vector<vector<pair<int, int>>> route{
	{pair<int,int>(0,1),pair<int,int>(1,2),pair<int,int>(2,3)},
	{pair<int,int>(1,0),pair<int,int>(1,2),pair<int,int>(2,3)},
	{pair<int,int>(2,3),pair<int,int>(2,1),pair<int,int>(1,0)},
	{pair<int,int>(3,2),pair<int,int>(2,1),pair<int,int>(1,0)}
};

void Proc()
{
	for (const auto& d : order)
	{
		int index = d.first - 1;
		v[index].dir = d.second;
		vector<int> possible;
		possible.emplace_back(index);
		for (int i = 0; i < 3; i++)
		{
			int front = (route[index][i].first < route[index][i].second) ? route[index][i].first : route[index][i].second;
			int back = (route[index][i].first > route[index][i].second) ? route[index][i].first : route[index][i].second;
			//극이 달라 회전 목록에 넣어놓기
			if (v[front].dq[3 - 1] != v[back].dq[7 - 1])
			{
				v[route[index][i].second].dir = (v[route[index][i].first].dir * -1);
				possible.emplace_back(route[index][i].second);
			}
			//극이 같아 회전하지 않음.
			else
			{
				if (route[index][i].second == 1 || route[index][i].second == 2)
				{
					break;
				}
			}
		}
		//possible 안에 내용 돌리기 (극이 달라 회전이 가능한 목록)
		for (const auto& r : possible)
		{
			//시계 방향이라면
			if (v[r].dir == 1)
			{
				v[r].dq.emplace_front(v[r].dq[7]);
				v[r].dq.pop_back();
			}
			//반 시계 방향이라면
			else
			{
				v[r].dq.emplace_back(v[r].dq[0]);
				v[r].dq.pop_front();
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	v = vector<TopNi>(4, TopNi());
	for (int i = 0; i < 4; i++)
	{
		string s = "";
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			v[i].dq[j] = (s[j] - '0');
		}
	}
	cin >> K;
	order = vector<pair<int, int>>(K, pair<int, int>(0, 0));
	for (int i = 0; i < K; i++)
	{
		cin >> order[i].first >> order[i].second;
	}
	Proc();
	ans += (v[0].dq[0] > 0) ? 1 : 0;
	ans += (v[1].dq[0] > 0) ? 2 : 0;
	ans += (v[2].dq[0] > 0) ? 4 : 0;
	ans += (v[3].dq[0] > 0) ? 8 : 0;
	cout << ans << "\n";
	return 0;
}