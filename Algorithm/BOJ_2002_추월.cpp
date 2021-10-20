#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
/*
4�����ʹ� q2���� ���ϰ� �������� q1���� �����־� ������ �߻���ų ����� ����.
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
//q1�� q2���� �̹� �񱳸� ������ ���� �����͸� Ȯ���ϱ�����
map<string, bool> m;
void Proc()
{
	//�ϳ��� �������� ���
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