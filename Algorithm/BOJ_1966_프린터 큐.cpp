#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> priority;
vector<pair<int, int>> v;

void Proc()
{
	int answer = 1;
	sort(priority.begin(), priority.end());
	while (true)
	{
		//현재 가장 높은 우선 순위
		int back = priority[priority.size() - 1];
		//현재 가장 앞에 출력될 문서가 우선순위가 가장 높지 않다면
		if (back != v[0].second)
		{
			//뒤로 보내기
			v.push_back(v[0]);
			v.erase(v.begin());
		}
		//현재 가장 앞에 출력될 문서가 우선순위가 가장 높다면
		else //if (back == v[0].second)
		{
			//출력될 문서가 원하던 문서인지
			if (v[0].first == M)
			{
				cout << answer << "\n";
				break;
			}
			//우선순위 높은 문서 내보내기
			priority.pop_back();
			v.erase(v.begin());
			answer++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int testCase = 0;
	cin >> testCase;
	for (int t = 0; t < testCase; t++)
	{
		cin >> N >> M;
		priority = vector<int>(N, 0);
		v = vector<pair<int, int>>(N, pair<int, int>(0, 0));
		for (int i = 0; i < N; i++)
		{
			int num = 0;
			cin >> num;
			priority[i] = num;
			v[i] = pair<int, int>(i, num);
		}
		Proc();
	}
}