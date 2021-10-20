#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 1;
	int curWeight = 0;
	vector<pair<int, int>> bridge;
	while (!truck_weights.empty() || !bridge.empty())
	{
		if (!truck_weights.empty() && curWeight + truck_weights[0] <= weight)
		{
			curWeight += truck_weights[0];
			bridge.emplace_back(truck_weights[0], 0);
			truck_weights.erase(truck_weights.begin());
		}
		int popCnt = 0;
		for (auto& d : bridge)
		{
			d.second++;
			if (d.second >= bridge_length)
			{
				curWeight -= d.first;
				popCnt++;
			}
		}
		for (int i = 0; i < popCnt; i++)
		{
			bridge.erase(bridge.begin());
		}
		answer++;
	}
	return answer;
}