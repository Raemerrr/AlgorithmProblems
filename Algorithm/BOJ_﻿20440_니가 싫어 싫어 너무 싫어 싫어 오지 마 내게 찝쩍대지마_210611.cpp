#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;
vector<int> sum;
vector<int> idx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v.assign(N, pair<int, int>(0, 0));
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second;
		idx.push_back(v[i].first), idx.push_back(v[i].second);
	}
	// ���� �� �ߺ� ������ ����
	sort(idx.begin(), idx.end());
	idx.erase(unique(idx.begin(), idx.end()), idx.end());

	// *��ǥ ����
	for (auto& d : v) {
		d.first = (lower_bound(idx.begin(), idx.end(), d.first) - idx.begin());
		d.second = (lower_bound(idx.begin(), idx.end(), d.second) - idx.begin());
	}
	sum.assign(idx.size(), 0);
	// ������ ���ϱ� �� �۾� : ����� ���� �ð� : +1, ����� ���� �ð� : -1
	for (const pair<int, int>& d : v) {
		sum[d.first] += 1;
		sum[d.second] -= 1;
	}
	//������
	for (int i = 0; i < idx.size(); i++) sum[i] = (i == 0) ? sum[i] : sum[i] + sum[i - 1];

	//���� ū �� �̾Ƴ���
	int maxVal = *max_element(sum.begin(), sum.end());

	//���� ū ���� ��ġ �˾Ƴ���
	auto it = find(sum.begin(), sum.end(), maxVal);

	//���� ū ���� ù �ε��� �˾Ƴ���
	int s = it - sum.begin();

	//���� ū ���� ������ ������.
	while (it != sum.end() && *it == maxVal) it++;

	//���� ū ���� �� �ε��� �˾Ƴ���
	int e = it - sum.begin();

	cout << maxVal << "\n";
	cout << idx[s] << " " << idx[e] << "\n";
	return 0;
}