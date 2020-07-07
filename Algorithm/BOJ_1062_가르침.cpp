#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace  std;

int N, K, ans;
vector<string> v;
map<char, bool> m{ {'a',true},{'n',true},{'t',true},{'i',true},{'c',true} };
int start_ = int('a');
int end_ = int('z');

void DFS(const int index, const int cnt)
{
	if (cnt == K)
	{
		int t_ans = 0;
		bool flag;
		for (const auto& d : v)
		{
			flag = true;
			for(const auto& z : d)
			{
				if (!m[z])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				t_ans++;
			}
		}
		ans = (ans > t_ans) ? ans : t_ans;
	}
	else
	{
		for (int i = index; i <= end_; i++)
		{
			char c = i;
			if (m[c]) { continue; }
			m[c] = true;
			DFS(i + 1, cnt + 1);
			m[c] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	K -= 5;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}
	if (K < 0)
	{
		cout << "0\n";
		return 0;
	}
	if (K >= 21)
	{
		cout << v.size() << "\n";
		return 0;
	}
	DFS(start_, 0);
	cout << ans << "\n";
	return 0;
}