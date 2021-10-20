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
	//성적순으로 입력
	while (N--)
	{
		string str;
		cin >> str;
		q.push(str);
	}
	//우선 상위 K명에 대한 처리 진행
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
	//순차적으로 처리 진행
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