#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Truck
{
	int weights;
	int createTime;
	Truck(int w, int c) {
		weights = w;
		createTime = c;
	}
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int localTime = 0, currentBridgeTotalWeight = 0;
	queue<Truck> bridge;
	queue<int> truck_weightsQ;
	for (const int truck_weight : truck_weights) {
		truck_weightsQ.push(truck_weight);
	}
	// 다리를 건너야할 트럭이 없으면서 다리를 건너고 있는 트럭이 없는 경우 종료
	while (!(truck_weightsQ.empty() && bridge.empty()))
	{
		// 다리의 가장 앞에 있는 트럭이 건널 수 있는 상태인지 확인
		if (!bridge.empty() && bridge.front().createTime + bridge_length <= localTime)
		{
			currentBridgeTotalWeight -= bridge.front().weights;
			bridge.pop();
		}
		if (!truck_weightsQ.empty())
		{
			// 대기중인 트럭을 다리에 올리는 로직
			Truck truck(truck_weightsQ.front(), localTime);
			if (bridge.size() < bridge_length && currentBridgeTotalWeight + truck.weights <= weight)
			{
				bridge.push(truck);
				currentBridgeTotalWeight += truck.weights;
				truck_weightsQ.pop();
			}
		}
		localTime++;
	}
	return localTime;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int bridge_length = 2;
	int weight = 10;
	vector<int> truck_weights{ 7,4,5,6 };
	cout << solution(bridge_length, weight, truck_weights) << "\n";
	return 0;
}
