/*
�ٸ� �ǳʱ� �˰���
����.
1. �ٸ��� �ǳʱ� ���� Ű�� ���� ����� �Բ� �ǳ� �� �ִ�.
2. �ٸ��� �ִ� �θ� �ö� �� �ִ�.
3. �ǳʴ� �ӵ��� ���� ��� �������� �ð��� �ҿ�ȴ�.
- ���� ���� �ǳʴ� ����� �ҿ�ð��� �˾Ƴ���.
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
		//������ ��
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
		//���ƿ��� ��
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