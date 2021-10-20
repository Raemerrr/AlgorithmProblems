#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace  std;

int N, K, ans;
vector<char> combi;
map<string, int> tempMap;
map<char, bool> m{ {'a',true},{'n',true},{'t',true},{'i',true},{'c',true} };

bool CheckWords(const char c)
{
	if (c != 'a' && c != 'n' && c != 't' && c != 'i' && c != 'c')
	{
		return true;
	}
	return false;
}

void DFS(const int index, const int cnt)
{
	if (cnt == K)
	{
		int t_ans = 0;
		bool flag;
		for (const auto& d : tempMap)
		{
			flag = true;
			for (const auto& z : d.first)
			{
				if (!m[z])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				t_ans += d.second;
			}
		}
		ans = (ans > t_ans) ? ans : t_ans;
	}
	else
	{
		for (int i = index; i < combi.size(); i++)
		{
			if (m[combi[i]]) { continue; }
			m[combi[i]] = true;
			DFS(i + 1, cnt + 1);
			m[combi[i]] = false;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	K -= 5;
	set<char> s;
	int maxWordSize = 0;
	for (int i = 0; i < N; i++)
	{
		set<char> t_s;
		string str;
		cin >> str;
		for (const auto& d : str)
		{
			if (CheckWords(d))
			{
				t_s.emplace(d);
			}
		}
		if (t_s.size() <= K)
		{
			tempMap[string(t_s.begin(), t_s.end())]++;
			s.insert(t_s.begin(), t_s.end());
			maxWordSize = (maxWordSize > t_s.size()) ? maxWordSize : t_s.size();
		}
	}
	if (K < 0)
	{
		cout << "0\n";
		return 0;
	}
	if (K >= 21)
	{
		cout << N << "\n";
		return 0;
	}
	if (s.size() < K)
	{
		K = s.size();
	}
	combi = vector<char>(s.begin(), s.end());
	DFS(0, 0);
	cout << ans << "\n";
	return 0;
}