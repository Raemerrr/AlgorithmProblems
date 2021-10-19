/*
�ٽ�..!

�ִ� ����, �ּ� ���� �̿��� �߰� ���� ã�´�!!

1. ù ��° ���� �߾� ������ ����
--�ݺ��� ����
2. �Է¹��� ���� �߾� ���� ���� �Է¹��� ���� ũ�� maxQ, ������ minQ�� �ִ´�.
3. ���� i�� Ȧ����� minQ�� maxQ �� ����� ���� Q�� �߾� �� push
4. ����� ū Q�� top�� center ������ ���� �� pop()

*�߿�.. ������ ��� ������ �� �� ��.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		int N = 0, center = 0;
		priority_queue<int> minQ;
		priority_queue<int, vector<int>, greater<int>> maxQ;
		vector<int> answer;
		cin >> N;
		cin >> center;
		answer.push_back(center);
		for (int i = 0; i < N - 1; i++)
		{
			int num = 0;
			cin >> num;
			if (center < num)
			{
				maxQ.push(num);
			}
			else
			{
				minQ.push(num);
			}
			//Ȧ����°����
			if (i & 1)
			{
				if (minQ.size() < maxQ.size())
				{
					minQ.push(center);
					center = maxQ.top();
					maxQ.pop();
				}
				else if (minQ.size() > maxQ.size())
				{
					maxQ.push(center);
					center = minQ.top();
					minQ.pop();
				}
				answer.push_back(center);
			}
		}
		//��� ���� ����...!!!
		cout << answer.size() << "\n";
		for (int i = 0; i < answer.size(); i++)
		{
			if (((i + 1) % 10) == 0 || (i == answer.size() - 1))
			{
				cout << answer[i] << "\n";
			}
			else
			{
				cout << answer[i] << " ";
			}
		}
	}
	return 0;
}