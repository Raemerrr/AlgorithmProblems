/*
작성일 : 2020-11-03
참고 : https://m.blog.naver.com/kks227/220795165570
투포인터 알고리즘
*/

#include <iostream>
#include <vector>

using namespace std;

int s, e, sum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> v{ 1,2,3,4,2,5,3,1,1,2 };
	int target = 5, answer = 0;
	while (true)
	{
		if (sum >= target)
		{
			sum -= v[s++];
		}
		else if (e == v.size())
		{
			break;
		}
		else
		{
			sum += v[e++];
		}
		if (sum == target)
		{
			answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}