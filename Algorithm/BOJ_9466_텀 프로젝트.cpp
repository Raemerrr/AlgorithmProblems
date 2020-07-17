#include <iostream>
#include <vector>

using namespace std;

int N, cnt;
//�湮 ������ ���� ����
vector<bool> check;
//Ž���� �� �� ���� �� �湮 ���θ� �Ǵ��ϴ� ����
vector<bool> visited;
//�����͸� ��� ���� ����
vector<int> v;

void Proc(const int startNode, const int currentNode)
{
	//����Ŭ�� ���� �� �̹� �湮�� ���� �־��ٸ�,
	if (visited[currentNode])
	{
		cnt++;
		//������� Ž�� ���� �� ����Ŭ�� �̷�� �� ī��Ʈ
		int temp = v[currentNode];
		while (temp != currentNode)
		{
			cnt++;
			temp = v[temp];
		}
	}
	else
	{
		visited[currentNode] = true;
		if (!check[v[currentNode]])
		{
			Proc(startNode, v[currentNode]);
			//�ѹ� �湮�� ���� �ٽ� �湮���� �ʵ���.
			check[currentNode] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		cin >> N;
		visited = vector<bool>(N + 1, false);
		check = vector<bool>(N + 1, false);
		v = vector<int>(N + 1, 0);
		cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			cin >> v[i];
		}
		for (int i = 1; i <= N; i++)
		{
			if (!check[i])
			{
				visited = vector<bool>(N + 1, false);
				Proc(i, i);
			}
		}
		cout << v.size() - cnt - 1 << "\n";
	}
	return 0;
}