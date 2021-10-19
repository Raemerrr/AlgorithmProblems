#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int N, idx, ans;
vector<string> v;
map<char, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v = vector<string>(N, "");
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	for (const auto& d : v)
	{
		idx = 0;
		for (auto it = d.rbegin(); it != d.rend(); it++)
		{
			m[*it] += pow(10, idx);
			idx++;
		}
	}
	//map에 담긴 값을 vector에 담아 정렬한다.
	vector<pair<char, int>> mapToVec(m.begin(), m.end());
	sort(mapToVec.begin(), mapToVec.end(), [](const pair<char, int>& a, const pair<char, int>& b)
	{
		return a.second > b.second;
	});

	//정렬 된 값을 9부터 차례로 부여한다.
	int val = 9;
	for (const auto& d : mapToVec)
	{
		m[d.first] = val;
		val--;
	}

	//부여된 값을 이용해 입력받은 string 계산을 한다.
	for (const auto& d : v)
	{
		int tAns = 0;
		idx = 0;
		for (auto i = d.rbegin(); i != d.rend(); i++)
		{
			tAns += m[*i] * pow(10, idx);
			idx++;
		}
		ans += tAns;
	}
	cout << ans << "\n";
	return 0;
}