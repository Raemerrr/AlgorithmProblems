#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, cnt;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> initQ;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> exitQ;
priority_queue<int, vector<int>, greater<int>> position;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v.assign(N, 0);
	for (int i = 0; i < N; i++)
	{
		//각 자리 별 착석 카운트를 하기 위해(최대 N대의 컴퓨터 존재 가능)
		position.push(i);
	}
	for (int i = 0; i < N; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		initQ.emplace(a, b);
	}
	int time = 0;
	while (!initQ.empty()) {
		//싸지방 나간 자리 확인 - 동시간 여러 사람이 나갈 경우 대비
		while (!exitQ.empty() && exitQ.top().first == time)
		{
			position.push(exitQ.top().second);
			exitQ.pop();
		}
		//싸지방 들어온 자리 확인 - 동시간 여러 사람이 들어올 경우 대비
		while (!initQ.empty() && initQ.top().first == time)
		{
			int curPos = position.top();
			v[curPos]++;
			exitQ.push({ initQ.top().second, curPos });
			initQ.pop();
			position.pop();
		}
		cnt = max((int)exitQ.size(), cnt);
		time++;
	}
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++) { cout << v[i] << " "; }
	return 0;
}