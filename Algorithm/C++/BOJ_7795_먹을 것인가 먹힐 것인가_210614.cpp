#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> A, B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0; cin >> test_case;
	while (test_case--)
	{
		cin >> N >> M;
		A.assign(N, 0);
		B.assign(M, 0);
		int answer = 0;
		for (int i = 0; i < N; i++) cin >> A[i];
		for (int i = 0; i < M; i++) cin >> B[i];
		sort(B.begin(), B.end());
		for (const int d : A) {
			int cnt = (lower_bound(B.begin(), B.end(), d) - B.begin());
			answer += cnt;
		}
		cout << answer << "\n";
	}
	return 0;
}