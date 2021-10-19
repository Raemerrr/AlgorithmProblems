#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int test_case;

void Proc(const map<char, set<string>>& m)
{
	for (const auto& d : m)
	{
		if (d.second.size() > 1)
		{
			vector<string> v(d.second.begin(), d.second.end());
			for (int i = 0; i < v.size() - 1; i++)
			{
				for (int j = i + 1; j < v.size(); j++)
				{
					if (v[i].size() < v[j].size())
					{
						//접두사 0번 인덱스부터 v[i] 사이즈만큼만 비교
						if (v[i] == v[j].substr(0, v[i].size()))
						{
							cout << "NO\n";
							return;
						}
					}
				}
			}
		}
	}
	cout << "YES\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> test_case;
	while (test_case > 0)
	{
		map<char, set<string>> m;
		int cnt = 0;
		cin >> cnt;
		for (int i = 0; i < cnt; i++)
		{
			string str = "";
			cin >> str;
			m[str[0]].emplace(str);
		}
		Proc(m);
		test_case--;
	}
	return 0;
}