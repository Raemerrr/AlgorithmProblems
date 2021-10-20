/*
핵심..!

최대 힙과, 최소 힙을 이용해 중간 값을 찾는다!!

1. 첫 번째 수를 중앙 값으로 설정
--반복문 시작
2. 입력받은 값과 중앙 값을 비교해 입력받은 값이 크면 maxQ, 작으면 minQ로 넣는다.
3. 현재 i가 홀수라면 minQ와 maxQ 중 사이즈가 작은 Q로 중앙 값 push
4. 사이즈가 큰 Q의 top을 center 값으로 설정 후 pop()

*중요.. 문제의 출력 형식을 잘 볼 것.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		int N = 0, center = 0;
		priority_queue<int> minQ;
		priority_queue<int, vector<int>, greater<int>> maxQ;
		vector<int> answer;
		cin >> N;
		cin >> center;
		answer.push_back(center);
		for (int i = 0; i < N - 1; i++)
		{
			int num = 0;
			cin >> num;
			if (center < num)
			{
				maxQ.push(num);
			}
			else
			{
				minQ.push(num);
			}
			//홀수번째인지
			if (i & 1)
			{
				if (minQ.size() < maxQ.size())
				{
					minQ.push(center);
					center = maxQ.top();
					maxQ.pop();
				}
				else if (minQ.size() > maxQ.size())
				{
					maxQ.push(center);
					center = minQ.top();
					minQ.pop();
				}
				answer.push_back(center);
			}
		}
		//출력 형식 주의...!!!
		cout << answer.size() << "\n";
		for (int i = 0; i < answer.size(); i++)
		{
			if (((i + 1) % 10) == 0 || (i == answer.size() - 1))
			{
				cout << answer[i] << "\n";
			}
			else
			{
				cout << answer[i] << " ";
			}
		}
	}
	return 0;
}