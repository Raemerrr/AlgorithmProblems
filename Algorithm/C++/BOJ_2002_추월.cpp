#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
/*
4데이터는 q2에서 비교하고 나갔지만 q1에는 남아있어 문제를 발생시킬 우려가 있음.
5
1
2
3
4
5
1
2
4
3
5
*/
using namespace std;
int N, ans;
queue<string> q1, q2;
//q1에 q2에서 이미 비교를 끝내고 나간 데이터를 확인하기위해
map<string, bool> m;
void Proc()
{
	//하나를 기준으로 잡고
	while (!q2.empty())
	{
		while (m[q1.front()])
		{
			cout << q1.front() << "\n";
			q1.pop();
		}
		if (q1.front() == q2.front())
		{
			q1.pop();
		}
		else
		{
			m[q2.front()] = true;
			ans++;
		}
		q2.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;
		q1.emplace(str);
	}
	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;
		q2.emplace(str);
	}
	Proc();
	cout << ans << "\n";
	return 0;
}