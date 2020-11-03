#include <iostream>
#include <vector>

using namespace std;

int N, s, e, sum, answer;
vector<bool> visited;
vector<int> primes;

void SetPrime()
{
	//�Ҽ� ã��
	visited[1] = true;
	for (int i = 1; i*i <= N; i++)
	{
		if (!visited[i])
		{
			for (int j = i * i; j <= N; j += i)
			{
				visited[j] = true;
			}
		}
	}

	//�Ҽ� �Է�
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			primes.push_back(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	visited = vector<bool>(N + 1, false);
	SetPrime();
	//�� �����͸� �̿��� ������ ã��
	while (true)
	{
		if (sum >= N)
		{
			sum -= primes[s++];
		}
		else if (e == primes.size())
		{
			break;
		}
		else
		{
			sum += primes[e++];
		}
		if (sum == N)
		{
			answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}