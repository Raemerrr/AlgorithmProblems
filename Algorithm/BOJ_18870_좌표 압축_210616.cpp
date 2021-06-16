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
	// ���� �� �ߺ� ���� - ���� �������� �ε����� �Ѵ�.
	vector<int> idx(v.begin(), v.end());
	sort(idx.begin(), idx.end());
	idx.erase(unique(idx.begin(), idx.end()), idx.end());
	//���� ���
	for (const auto d : v) {
		//���� ���� �ε��� ��� (���� ���� ��ġ)
		cout << (lower_bound(idx.begin(), idx.end(), d) - idx.begin()) << " ";
	}
	cout << "\n";
	return 0;
}