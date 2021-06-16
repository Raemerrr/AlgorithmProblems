#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
int n;
LL answer;
vector<int> A, B, C, D;
vector<LL> sum1, sum2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	A.assign(n, 0), B.assign(n, 0), C.assign(n, 0), D.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum1.push_back(A[i] + B[j]);
			sum2.push_back(C[i] + D[j]);
		}
	}
	sort(sum2.begin(), sum2.end());
	for (const auto& d : sum1) {
		int temp = (upper_bound(sum2.begin(), sum2.end(), -d) - lower_bound(sum2.begin(), sum2.end(), -d));
		answer += temp;
	}
	cout << answer << "\n";
	return 0;
}