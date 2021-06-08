#include <iostream>
#include <deque>
#include <algorithm>
#include <set>

using namespace std;

typedef unsigned long long ULL;
deque<int> A;
deque<int> B;
deque<ULL> aSum;
deque<ULL> bSum;
int N, M, K, answer;
set<ULL> s;

void Proc(deque<ULL>& sum, deque<int>& values, int Size, bool flag) {
	for (int i = 0; i < Size; i++)
	{
		int loopSize = (i == 0) ? Size : Size - 1;
		deque<ULL> tempSum(loopSize, 0);
		for (int j = 0; j < loopSize; j++)
		{
			tempSum[j] += (j == 0) ? values[j] : values[j] + tempSum[j - 1];
			if (flag) s.insert(tempSum[j]);
			answer += (tempSum[j] == K) ? 1 : 0;
		}
		sum.insert(sum.end(), tempSum.begin(), tempSum.end());
		values.push_back(values.front());
		values.pop_front();
	}
	sort(sum.begin(), sum.end());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> K >> N >> M;
	A.assign(N, 0);
	B.assign(M, 0);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < M; i++) cin >> B[i];
	Proc(aSum, A, N, true);
	Proc(bSum, B, M, false);
	for (const int d : s) {
		int tempCnt = 0;
		if (d >= K)
		{
			break;
		}
		tempCnt = (upper_bound(aSum.begin(), aSum.end(), d) - lower_bound(aSum.begin(), aSum.end(), d));
		auto it = lower_bound(bSum.begin(), bSum.end(), K - d);
		if (it != bSum.end() && (*it) == K - d)
		{
			tempCnt *= (upper_bound(bSum.begin(), bSum.end(), K - d) - it);
			answer += tempCnt;
		}

	}
	cout << answer << "\n";
	return 0;
}