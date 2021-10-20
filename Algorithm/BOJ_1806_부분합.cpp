#include <iostream>
#include <vector>

using namespace std;

int s, e, sum, answer, N, M;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	v = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	//�켱 �ִ� ���̷� �ʱ�ȭ
	answer = N + 1;
	while (true)
	{
		if (sum >= M)
		{
			answer = answer < (e - s) ? answer : (e - s);
			sum -= v[s++];
		}
		else if (e == v.size())
		{
			break;
		}
		else
		{
			sum += v[e++];
		}
	}
	//�ִ� ���̺��� ũ�ų� ���ٸ� �κ��� ������ ������ �ǹ�.
	if (answer >= N + 1)
	{
		cout << "0\n";
	}
	else
	{
		cout << answer << "\n";
	}
	return 0;
}