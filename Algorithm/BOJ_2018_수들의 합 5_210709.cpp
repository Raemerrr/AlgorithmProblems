#include <iostream>

using namespace std;

int N, answer = 1, s = 1, sum = 1, e = 2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		if (sum >= N)
		{
			answer = (sum == N) ? answer + 1 : answer;
			sum -= s++;
		}
		else
		{
			sum += e++;
		}
	}
	cout << answer << "\n";
	return 0;
}