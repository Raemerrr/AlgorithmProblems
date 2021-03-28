#include <iostream>
#include <queue>

using namespace std;

int N, input, MID;
priority_queue<int, vector<int>, less<int>> minQ;
priority_queue<int, vector<int>, greater<int>> maxQ;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> MID;
	cout << MID << "\n";
	for (int i = 2; i <= N; i++)
	{
		cin >> input;
		if (input < MID)
		{
			minQ.push(input);
		}
		else
		{
			maxQ.push(input);
		}
		//홀수 번째
		//minQ.size == maxQ.size 해야 정상
		if (i % 2 != 0)
		{
			if (minQ.size() < maxQ.size())
			{
				minQ.push(MID);
				MID = maxQ.top();
				maxQ.pop();
			}
			else if (minQ.size() > maxQ.size())
			{
				maxQ.push(MID);
				MID = minQ.top();
				minQ.pop();
			}
			cout << MID << "\n";
		}
		//짝수번째 입력
		else
		{
			if (minQ.size() < maxQ.size())
			{
				cout << ((MID < maxQ.top()) ? MID : maxQ.top()) << "\n";
			}
			else //if (minQ.size() > maxQ.size())
			{
				cout << ((MID < minQ.top()) ? MID : minQ.top()) << "\n";
			}
		}
	}
	return 0;
}