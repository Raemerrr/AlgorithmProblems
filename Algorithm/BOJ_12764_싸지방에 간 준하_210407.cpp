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
		//�� �ڸ� �� ���� ī��Ʈ�� �ϱ� ����(�ִ� N���� ��ǻ�� ���� ����)
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
		//������ ���� �ڸ� Ȯ�� - ���ð� ���� ����� ���� ��� ���
		while (!exitQ.empty() && exitQ.top().first == time)
		{
			position.push(exitQ.top().second);
			exitQ.pop();
		}
		//������ ���� �ڸ� Ȯ�� - ���ð� ���� ����� ���� ��� ���
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