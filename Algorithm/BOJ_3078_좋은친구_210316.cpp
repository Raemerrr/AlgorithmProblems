#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

typedef long long LL;

int N, K;
LL ans;
queue<string> q;
queue<string> deleteQ;
map<int, LL> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	//���������� �Է�
	while (N--)
	{
		string str;
		cin >> str;
		q.push(str);
	}
	//�켱 ���� K�� ���� ó�� ����
	while (K--)
	{
		string front = q.front();
		q.pop();
		if (m[front.size()] > 0)
		{
			ans += m[front.size()];
		}
		m[front.size()]++;
		deleteQ.push(front);
	}
	//���������� ó�� ����
	while (!q.empty())
	{
		string front = q.front();
		q.pop();
		if (m[front.size()] > 0)
		{
			ans += m[front.size()];
		}
		m[front.size()]++;
		deleteQ.push(front);
		if (!deleteQ.empty())
		{
			front = deleteQ.front();
			deleteQ.pop();
			m[front.size()]--;
		}
	}
	cout << ans << "\n";
	return 0;
}