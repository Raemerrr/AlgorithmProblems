#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
vector<int> qa;
vector<float> price;

map<int, float> m;

void Proc()
{
	int beforeID = -1;
	int afterID = -1;
	for (const auto d : m)
	{
		if (d.second >= 0.0)
		{
			if (d.first < N)
			{
				beforeID = d.first;
			}
			else if (d.first > N)
			{
				afterID = d.first;
			}
			//구간을 찾았다고 판단
			if (beforeID != -1 && afterID != -1)
			{
				break;
			}
			else if (beforeID == -1)
			{
				break;
			}
		}
	}
	//작은 값이 없다면
	if (beforeID == -1)
	{
		int i = 0;
		for (auto z : m)
		{
			if (i == 2)
			{
				break;
			}
			if (z.second >= 0.0)
			{
				if (i == 0)
				{
					beforeID = z.first;
				}
				else
				{
					afterID = z.first;
				}
				i++;
			}
		}
	}
	//큰 값이 없다면
	else if (afterID == -1)
	{
		int tempID = -1;
		afterID = beforeID;
		for (auto d : m)
		{
			if (d.second > 0.0)
			{
				if (d.first >= afterID)
				{
					break;
				}
				tempID = d.first;
			}
		}
		beforeID = tempID;
	}
	int num = afterID - beforeID;
	float dif = m[afterID] - m[beforeID];
	dif = round(dif * 100) / 100;
	float d = dif / num;
	dif = round(d * 100) / 100;
	float point = m[beforeID] - (beforeID * d);
	dif = round(point * 100) / 100;
	float ans = point + (d*N);
	cout << round(ans * 100) / 100 << "\n";
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> M;
	qa = vector<int>(M, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> qa[i];
	}
	cin >> M;
	price = vector<float>(M, 0.0);
	for (int i = 0; i < M; i++)
	{
		cin >> m[qa[i]];
	}
	if (m[N] != 0.0)
	{
		cout << round(m[N] * 100) / 100 << "\n";
	}
	else
	{
		m.erase(N);
		Proc();
	}
	return 0;
}