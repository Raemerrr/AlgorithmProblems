#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;
int N, MAX = -1000000000, MIN = 1000000000;
//�Է� �� ����
vector<int> v;
//������ ���� 
vector<char> c;
//������ ���� ����
set<vector<char>> s;
char cArr[4]{ '+','-','*','/' };
//�ӽ� ������ ����
vector<char> tempArr;
//������ ���� �� ��湮 �Ǵ�
vector<bool> visited;

//������ ���� ���ϱ�
void Combi()
{
	if (tempArr.size() == N - 1)
	{
		s.emplace(tempArr);
	}
	else
	{
		for (int i = 0; i < c.size(); i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				tempArr.emplace_back(c[i]);
				Combi();
				tempArr.pop_back();
				visited[i] = false;
			}
		}
	}
}

//�����
void Proc()
{
	for (const auto& d : s)
	{
		int i = 1;
		int res = v[0];
		for (const auto& t : d)
		{
			if (t == '+')
			{
				res = res + v[i];
			}
			else if (t == '-')
			{
				res = res - v[i];
			}
			else if (t == '*')
			{
				res = res * v[i];
			}
			// t == '/'
			else
			{
				if (res < 0)
				{
					//����� �ٲٰ�
					res *= -1;
					res = ((res / v[i]) * -1);
				}
				else
				{
					res = (res / v[i]);
				}
			}
			i++;
		}
		MAX = (MAX > res) ? MAX : res;
		MIN = (MIN < res) ? MIN : res;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	//��ȣ�� 4����
	for (int i = 0; i < 4; i++)
	{
		int num = 0;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			//�׿� �´� ��ȣ�� �־� �����Ϸ���...
			c.emplace_back(cArr[i]);
		}
	}
	visited = vector<bool>(c.size(), false);
	Combi();
	Proc();
	cout << MAX << "\n" << MIN << "\n";
	return 0;
}