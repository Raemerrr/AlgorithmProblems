#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long LL;

vector<LL> v;
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--)
	{
		string str; cin >> str;
		reverse(str.begin(), str.end());
		v.push_back(stoll(str));
	}
	sort(v.begin(), v.end());
	for (const LL& d : v) { cout << d << "\n"; }
	return 0;
}