#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;
vector<int> sum1;
vector<int> sum2;
vector<int> sum3;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v.assign(N, 0);
	sum1.assign(N, 0);
	sum2.assign(N, 0);
	sum3.assign(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		if (v[i] == 1)
		{
			sum1[i] += (i == 0) ? 1 : sum1[i - 1] + 1;
			sum2[i] += (i == 0) ? 0 : sum2[i - 1];
			sum3[i] += (i == 0) ? 0 : sum3[i - 1];
		}
		else if (v[i] == 2)
		{
			sum1[i] += (i == 0) ? 0 : sum1[i - 1];
			sum2[i] += (i == 0) ? 1 : sum2[i - 1] + 1;
			sum3[i] += (i == 0) ? 0 : sum3[i - 1];
		}
		else
		{
			sum1[i] += (i == 0) ? 0 : sum1[i - 1];
			sum2[i] += (i == 0) ? 0 : sum2[i - 1];
			sum3[i] += (i == 0) ? 1 : sum3[i - 1] + 1;
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
