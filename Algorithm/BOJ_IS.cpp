#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	/*string s = "avbc.x";
	auto a = s.find('.');
	cout << a << "\n";
	s.erase(s.begin()+a,s.end());
	cout << s << "\n";
	return 0;*/
	string pattern;
	int N;
	cin >> pattern >> N;
	vector<string> files = vector<string>(N,"");
	for (int i = 0; i < N; i++)
	{
		cin >> files[i];
	}
	for (int i = 0; i < pattern.size(); i++)
	{
		char findChar = ' ';
		if (pattern[i] == '*' && i == pattern.size() - 1)
		{
			findChar = pattern[i - 1];
			for (auto& d : files)
			{
				if (!d.empty())
				{
					int dist = d.find(findChar);
					d.erase(d.begin() + dist + 1, d.end());
				}
			}
		}
		else if (pattern[i] == '*' && i < pattern.size()-1)
		{
			findChar = pattern[i + 1];
			for (auto& d : files) 
			{
				if (!d.empty())
				{
					int dist = d.find(findChar);
					dist += 1;
					d.erase(d.begin(), d.begin() + dist);
				}
			}
			i++;
		}
		else
		{
			findChar = pattern[i];
			for (auto& d : files)
			{
				if (!d.empty())
				{
					int dist = d.find(findChar);
					d.erase(d.begin() + dist);
				}
			}
		}
	}
	return 0;
}