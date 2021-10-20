#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int N;
//�νľ� ������ ������ �����ϴ� ����
map<string, int> m{ {"a",1},{"b",2},{"k",3},{"d",4},{"e",5},{"g",6},{"h",7},
{"i",8},{"l",9},{"m",10},{"n",11},{"ng",12},{"o",13},{"p",14},{"r",15},{"s",16},
{"t",17},{"u",18},{"w",19},{"y",20} };

vector<string> str;

void Proc()
{
	//string�� �ش� �ܾ�, vector<int>�� �ܾ��� ���� �� ���� ���� ���  ex ) abk : {1,2,3}, ngng : {12,12}, ngngg : {12,12,6}
	vector<pair<string, vector<int>>> v(N, pair<string, vector<int>>("", vector<int>()));
	for (int i = 0; i < str.size(); i++)
	{
		v[i].first = str[i];
		for (int j = 0; j < str[i].size(); j++)
		{
			if (str[i][j] != 'n')
			{
				v[i].second.push_back(m[string(1, str[i][j])]);
			}
			else
			{
				if (j < str[i].size() - 1 && str[i][j + 1] == 'g')
				{
					v[i].second.push_back(m["ng"]);
					j++;
				}
				else
				{
					v[i].second.push_back(m["n"]);
				}
			}
		}
	}
	sort(v.begin(), v.end(), [](const pair<string, vector<int>>& a, const pair<string, vector<int>>& b) {
		//ª�� �迭 �������� ��
		int len = (a.second.size() < b.second.size()) ? a.second.size() : b.second.size();
		for (int i = 0; i < len; i++)
		{
			if (a.second[i] != b.second[i])
			{
				return a.second[i] < b.second[i];
			}
		}
		//���̰� ª�� �迭�̶� ������ �Ȱ��ٸ� ���� ª������ ����
		return a.second.size() < b.second.size();
	});

	for (const auto& d : v) { cout << d.first << "\n"; }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	str = vector<string>(N, "");
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
	}
	Proc();
	return 0;
}