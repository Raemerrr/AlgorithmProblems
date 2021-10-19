#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int aSize, bSize;
vector<int> A;
vector<int> B;
vector<int> answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> aSize >> bSize;
	A.assign(aSize, 0);
	B.assign(bSize, 0);
	for (int i = 0; i < aSize; i++) cin >> A[i];
	for (int i = 0; i < bSize; i++) cin >> B[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (const int d : A) {
		//lower_bound : 'd' 이상 처음 나오는 iterator
		auto it = lower_bound(B.begin(), B.end(), d);
		if (it == B.end() || (*it) != d)
		{
			answer.push_back(d);
		}
	}
	cout << answer.size() << "\n";
	for (const int d : answer) cout << d << " "; cout << "\n";
	return 0;
}