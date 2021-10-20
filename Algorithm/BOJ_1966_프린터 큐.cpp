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
		//���� ���� ���� �켱 ����
		int back = priority[priority.size() - 1];
		//���� ���� �տ� ��µ� ������ �켱������ ���� ���� �ʴٸ�
		if (back != v[0].second)
		{
			//�ڷ� ������
			v.push_back(v[0]);
			v.erase(v.begin());
		}
		//���� ���� �տ� ��µ� ������ �켱������ ���� ���ٸ�
		else //if (back == v[0].second)
		{
			//��µ� ������ ���ϴ� ��������
			if (v[0].first == M)
			{
				cout << answer << "\n";
				break;
			}
			//�켱���� ���� ���� ��������
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