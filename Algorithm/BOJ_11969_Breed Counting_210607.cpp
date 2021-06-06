#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> sum1;
vector<int> sum2;
vector<int> sum3;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	sum1.assign(N, 0);
	sum2.assign(N, 0);
	sum3.assign(N, 0);
	for (int i = 0; i < N; i++)
	{
		int num = 0; cin >> num;
		if (i == 0)
		{
			sum1[i] += ((num == 1) ? 1 : 0);
			sum2[i] += ((num == 2) ? 1 : 0);
			sum3[i] += ((num == 3) ? 1 : 0);
		}
		else
		{
			sum1[i] += sum1[i - 1] + ((num == 1) ? 1 : 0);
			sum2[i] += sum2[i - 1] + ((num == 2) ? 1 : 0);
			sum3[i] += sum3[i - 1] + ((num == 3) ? 1 : 0);
		}
	}
	while (M--)
	{
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2; num1--, num2--;
		cout << (sum1[num2] - ((num1 == 0) ? 0 : sum1[num1 - 1])) << " ";
		cout << (sum2[num2] - ((num1 == 0) ? 0 : sum2[num1 - 1])) << " ";
		cout << (sum3[num2] - ((num1 == 0) ? 0 : sum3[num1 - 1])) << "\n";
	}
	return 0;
}
