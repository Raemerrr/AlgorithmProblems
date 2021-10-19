#include <iostream>
#include <vector>
#include <string>

using namespace std;
int N;
int totalT;
vector<string> map;
//행
vector<int> row;
//열
vector<int> col;

vector<vector<int>> combi;
vector<int> temp;
int comSize;
int ans;
void combination(const int index)
{
	if (temp.size() == comSize)
	{
		combi.emplace_back(temp);
	}
	else
	{
		for (int i = index; i < N; i++)
		{
			temp.emplace_back(i);
			combination(i + 1);
			temp.pop_back();
		}
	}
}

void Proc()
{
	int tempTotalT = 0;
	for (const auto& d : combi)
	{
		tempTotalT = totalT;
		//행 한번
		for (const auto& z : d)
		{
			tempTotalT = tempTotalT - row[z] + N - row[z];
			if (tempTotalT < 2)
			{
				tempTotalT = totalT;
				break;
			}
		}
		ans = (ans < tempTotalT) ? ans : tempTotalT;
		if (d.size() < N)
		{
			tempTotalT = totalT;
			//열 한번
			for (const auto& z : d)
			{
				tempTotalT = tempTotalT - col[z] + N - col[z];
				if (tempTotalT < 2)
				{
					tempTotalT = totalT;
					break;
				}
			}
			ans = (ans < tempTotalT) ? ans : tempTotalT;
		}
		if (ans == 2)
		{
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	ans = N * N;
	map = vector<string>(N, "");
	row = vector<int>(N, 0);
	col = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'T')
			{
				col[j]++;
				row[i]++;
				totalT++;
			}
		}
	}
	cout << "col : ";
	for (auto d : col) { cout << d << " "; }cout << "\n";
	cout << "row : ";
	for (auto d : row) { cout << d << " "; }cout << "\n";
	cout << "totalT : " << totalT << "\n";

	for (int i = 1; i <= N; i++)
	{
		comSize = i;
		//조합
		combination(0);
	}
	for (auto z : combi)
	{
		for (auto d : z)
		{
			cout << d << " ";
		}
		cout << "\n";
	}
	Proc();
	cout << ans << "\n";
	return 0;
}