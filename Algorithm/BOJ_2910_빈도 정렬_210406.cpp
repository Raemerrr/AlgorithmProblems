#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N, C;
map<int, pair<int, int>> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		//ó�� �����ϴ� ���̶��
		if (!m.count(num))
		{
			m[num].first = i;
			m[num].second = 1;
		}
		else
		{
			m[num].second++;
		}
	}
	vector<pair<int, pair<int, int>>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
		if (a.second.second == b.second.second)
		{
			//���� ��ġ�� ���� ��
			return a.second.first < b.second.first;
		}
		//�󵵰� ���� ��
		return a.second.second > b.second.second;
	});
	for (const pair<int, pair<int, int>>& d : v)
	{
		for (int i = 0; i < d.second.second; i++)
		{
			cout << d.first << " ";
		}
	}
	return 0;
}