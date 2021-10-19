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
	//map�� ��� ���� vector�� ��� �����Ѵ�.
	vector<pair<char, int>> mapToVec(m.begin(), m.end());
	sort(mapToVec.begin(), mapToVec.end(), [](const pair<char, int>& a, const pair<char, int>& b)
	{
		return a.second > b.second;
	});

	//���� �� ���� 9���� ���ʷ� �ο��Ѵ�.
	int val = 9;
	for (const auto& d : mapToVec)
	{
		m[d.first] = val;
		val--;
	}

	//�ο��� ���� �̿��� �Է¹��� string ����� �Ѵ�.
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