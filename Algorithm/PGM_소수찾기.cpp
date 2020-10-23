#include <string>
#include <vector>
#include <set>
using namespace std;

//비효율적인.. 소수 구하기
bool CheckPrime(const int num)
{
	if (num < 2)
	{
		return false;
	}
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int tempSize;
string combiStr;
vector<bool> visited;
vector<char> temp;
set<int> combi;

void bfs(const int index)
{
	if (temp.size() == tempSize)
	{
		combi.emplace(stoi(string(temp.begin(), temp.end())));
	}
	else
	{
		for (int i = 0; i < combiStr.size(); i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				temp.push_back(combiStr[i]);
				bfs(i);
				temp.pop_back();
				visited[i] = false;
			}
		}
	}
}

int solution(string numbers) {
	int answer = 0;
	combiStr = numbers;
	for (int i = 1; i <= combiStr.size(); i++)
	{
		visited = vector<bool>(combiStr.size(), false);
		tempSize = i;
		bfs(0);
	}
	for (const auto& d : combi)
	{
		if (CheckPrime(d)) { answer++; }
	}
	return answer;
}