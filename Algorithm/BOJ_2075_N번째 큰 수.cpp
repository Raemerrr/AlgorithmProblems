#include <iostream>
#include <queue>

using namespace std;
int N;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int> pq;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num = 0;
			cin >> num;
			if (pq.size() < N)
			{
				pq.emplace(-num);
			}
			else
			{
				pq.emplace(-num);
				pq.pop();
			}
		}
	}
	cout << -pq.top() << "\n";
	return 0;
}