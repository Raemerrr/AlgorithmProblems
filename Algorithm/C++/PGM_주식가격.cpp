#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size(), 0);
	answer[0] = 1;
	vector<pair<int, int>> temp{ pair<int,int>(prices[0],0) };
	for (int i = 1; i < prices.size() - 1; i++)
	{
		while (!temp.empty() && temp[temp.size() - 1].first > prices[i])
		{
			temp.pop_back();
		}
		temp.emplace_back(prices[i], i);
		for (const auto& d : temp)
		{
			answer[d.second]++;
		}
	}
	return answer;
}