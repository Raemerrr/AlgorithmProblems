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
	// 정렬 후 중복 아이템 제거
	sort(idx.begin(), idx.end());
	idx.erase(unique(idx.begin(), idx.end()), idx.end());

	// *좌표 압축
	for (auto& d : v) {
		d.first = (lower_bound(idx.begin(), idx.end(), d.first) - idx.begin());
		d.second = (lower_bound(idx.begin(), idx.end(), d.second) - idx.begin());
	}
	sum.assign(idx.size(), 0);
	// 누적합 구하기 전 작업 : 모기의 입장 시간 : +1, 모기의 퇴장 시간 : -1
	for (const pair<int, int>& d : v) {
		sum[d.first] += 1;
		sum[d.second] -= 1;
	}
	//누적합
	for (int i = 0; i < idx.size(); i++) sum[i] = (i == 0) ? sum[i] : sum[i] + sum[i - 1];

	//가장 큰 값 뽑아내기
	int maxVal = *max_element(sum.begin(), sum.end());

	//가장 큰 값의 위치 알아내기
	auto it = find(sum.begin(), sum.end(), maxVal);

	//가장 큰 값의 첫 인덱스 알아내기
	int s = it - sum.begin();

	//가장 큰 값의 구간을 지난다.
	while (it != sum.end() && *it == maxVal) it++;

	//가장 큰 값의 끝 인덱스 알아내기
	int e = it - sum.begin();

	cout << maxVal << "\n";
	cout << idx[s] << " " << idx[e] << "\n";
	return 0;
}