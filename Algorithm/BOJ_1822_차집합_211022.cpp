#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> A, B, answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	A.assign(N, 0), B.assign(M, 0);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < M; i++) cin >> B[i];
	sort(A.begin(), A.end()), sort(B.begin(), B.end());
	for (const int d : A) {
		auto it = lower_bound(B.begin(), B.end(), d);

		if (it == B.end() || d != *(it)) answer.push_back(d);
	}
	cout << answer.size() << "\n";
	for (const int d : answer) cout << d << " ";
	cout << "\n";
	return 0;
}