#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> v, answer(prices.size(), 0);
	for (int i = 0; i < prices.size(); i++)
	{
		while (!v.empty() && prices[i] < prices[v.back()])
		{
			answer[v.back()] = i - v.back();
			v.pop_back();
		}
		v.push_back(i);
	}
	while (!v.empty())
	{
		answer[v.back()] = prices.size() - 1 - v.back();
		v.pop_back();
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> prices{ 1,2,3,2,3 };
	for (const int d : solution(prices)) {
		cout << d << " ";
	}
	cout << "\n";
	return 0;
}