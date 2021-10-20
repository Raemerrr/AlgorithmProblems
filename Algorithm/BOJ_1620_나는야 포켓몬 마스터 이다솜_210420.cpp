#include <iostream>
#include <string>
#include <map>

using namespace std;

int N, M;
map<string, int> m;
map<int, string> idx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string str; cin >> str;
		m[str] = i;
		idx[i] = str;
	}
	while (M--)
	{
		string str; cin >> str;
		if (m.count(str))
		{
			cout << m[str] << "\n";
		}
		else
		{
			cout << idx[stoi(str)] << "\n";
		}
	}
	return 0;
}