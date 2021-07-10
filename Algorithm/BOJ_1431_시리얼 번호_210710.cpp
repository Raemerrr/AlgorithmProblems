#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
vector<string> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		string str; cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), [](const string& a, const string& b) {
		if (a.size() != b.size())
		{
			return a.size() < b.size();
		}
		else
		{
			int aSum = 0, bSum = 0;
			for (const char d : a) { aSum += (isalpha(d)) ? 0 : d - '0'; }
			for (const char d : b) { bSum += (isalpha(d)) ? 0 : d - '0'; }
			if (aSum == bSum)
			{
				return a < b;
			}
			return aSum < bSum;
		}
		});
	for (const string& s : v) { cout << s << "\n"; }
	return 0;
}