#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> v[i];
	// 정렬 후 중복 제거 - 오름 차순으로 인덱싱을 한다.
	vector<int> idx(v.begin(), v.end());
	sort(idx.begin(), idx.end());
	idx.erase(unique(idx.begin(), idx.end()), idx.end());
	//정답 출력
	for (const auto d : v) {
		//현재 값의 인덱스 출력 (현재 값의 위치)
		cout << (lower_bound(idx.begin(), idx.end(), d) - idx.begin()) << " ";
	}
	cout << "\n";
	return 0;
}