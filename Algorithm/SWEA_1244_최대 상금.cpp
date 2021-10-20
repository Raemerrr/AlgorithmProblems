#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> v;
//�ڸ� �ٲٱ� Ƚ��
int N;
//�ش� ������ ����
int length;

vector<int>  Proc()
{
	deque<vector<int>> store;
	store.emplace_back(v);
	for (int t = 0; t < N; t++)
	{
		//dfs()ó�� �����Ѵٰ� ���� �ȴ�.
		//size = store.size() ���� ����Ŭ���� ������ �ִ� ������ �� (���� ����Ŭ�� ���� X )
		for (int z = 0, size = store.size(); z < size; z++)
		{
			vector<int> front = store.front();
			store.pop_front();
			for (int i = 0; i < length - 1; i++)
			{
				for (int j = i + 1; j < length; j++)
				{
					vector<int> tempV = front;
					swap(tempV[i], tempV[j]);
					//����ҿ� �������� �ʴٸ� ����
					if (find(store.begin(), store.end(), tempV) == store.end())
					{
						store.emplace_back(tempV);
					}
				}
			}
		}
	}
	//���� �� ���� ū �� ��ȯ
	sort(store.begin(), store.end());
	return store.back();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 0;
	cin >> t;
	for (int test_case = 1; test_case <= t; test_case++)
	{
		string str = "";
		cin >> str >> N;
		v = vector<int>(str.size(), 0);
		length = str.size();
		for (int i = 0; i < str.size(); i++)
		{
			v[i] = str[i] - '0';
		}
		cout << "#" << test_case << " ";
		for (const auto& d : Proc()) { cout << d; } cout << "\n";
	}
	return 0;
}