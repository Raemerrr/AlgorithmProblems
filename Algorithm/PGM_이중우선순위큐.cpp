#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	priority_queue<int> pq;
	vector<int> nums;
	for (const auto& d : operations)
	{
		if (d == "D 1")
		{
			if (!pq.empty())
			{
				pq.pop();
			}
		}
		else if (d == "D -1")
		{
			if (!pq.empty())
			{
				vector<int> sortQ;
				while (!pq.empty())
				{
					sortQ.emplace_back(pq.top());
					pq.pop();
				}
				if (!sortQ.empty())
				{
					sort(sortQ.begin(), sortQ.end());
					sortQ.erase(sortQ.begin());
					pq = priority_queue<int>(sortQ.begin(), sortQ.end());
				}
			}
		}
		else
		{
			string numStr = string(d.begin() + 2, d.end());
			pq.emplace(stoi(numStr));
		}
	}
	while (!pq.empty())
	{
		nums.emplace_back(pq.top());
		pq.pop();
	}
	if (nums.empty())
	{
		answer = vector<int>{ 0,0 };
	}
	else
	{
		answer = vector<int>{ nums[0],nums[nums.size() - 1] };
	}
	return answer;
}