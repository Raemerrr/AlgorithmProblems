#include <iostream>

using namespace std;

int N, M, answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	answer = ((answer < M) ? M : answer);
	while (N--)
	{
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		M += num1;
		M -= num2;
		answer = ((answer < M) ? M : answer);
		if (M < 0)
		{
			answer = 0;
			break;
		}
	}
	cout << answer << "\n";
	return 0;
}