/*
다리 건너기 알고리즘
조건.
1. 다리를 건너기 위해 키를 가진 사람과 함께 건널 수 있다.
2. 다리는 최대 두명만 올라갈 수 있다.
3. 건너는 속도가 느린 사람 기준으로 시간이 소요된다.
- 가장 빨리 건너는 경우의 소요시간을 알아내라.
*/

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N, answer;
deque<int> B;
deque<int> A;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	B.assign(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}
	bool turn = false;
	while (!B.empty())
	{
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		//보내는 턴
		if (!turn)
		{
			if (A.empty() ||
				(B.size() >= 2 && A.front() > B[1]))
			{
				A.push_back(B.front()); B.pop_front();
				answer += B.front();
				A.push_back(B.front()); B.pop_front();
			}
			else
			{
				answer += B.back();
				A.push_back(B.back()); B.pop_back();
				A.push_back(B.back()); B.pop_back();
			}
		}
		//돌아오는 턴
		else
		{
			answer += A.front();
			B.push_back(A.front()); A.pop_front();
		}
		turn = !turn;
	}
	cout << answer << "\n";
	return 0;
}