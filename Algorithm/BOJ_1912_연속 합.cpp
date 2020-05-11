/*
2������ �����ϸ� �ȴ�.

1. dp[i-1] > 0
  - ������ ���� ������� ������ �ʿ� ���� ������� �ٽ� �����س����� �ȴ�.

  2. dp[i] + dp[i-1] > 0
  - ������ �հ� ������ ���� ���� ���� ������� ������ �ʿ䰡 ����.

6
-5 1 2 3 -4 5
correct answer: 7
*/
#include <iostream>
#include <vector>

using namespace std;
int N, ans;
vector<int> v;

void Proc()
{
	vector<int> dp(N, 0);
	dp[0] = v[0];
	//ans = 0���� �ϸ� ������ �ִ밪�� ���� �� ����.
	ans = dp[0];
	for (int i = 1; i < N; i++)
	{
		//���� ���ؼ� ���� ����...
		if (dp[i - 1] < 0)
		{
			//������� �ٽ� ����
			dp[i] = v[i];
		}
		else
		{
			//���ؼ� ������
			if (dp[i - 1] + v[i] > 0)
			{
				dp[i] = dp[i - 1] + v[i];
			}
			//���ؼ� ������� ���� ��꿡�� ������ ���� �������� 0 �ֱ� ��� ��� ����
			//�̹� 0���� �ʱ�ȭ �߱� ����
			//else
			//{
			//	dp[i] = 0;
			//}
		}
		ans = (ans > dp[i]) ? ans : dp[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	Proc();
	cout << ans << "\n";
	return 0;
}