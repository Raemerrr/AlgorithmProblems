#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

//2 : (0, 1)
//5 : (1, 1)
//8 : (2, 1)
//9 : (3, 1)
pair<int, int> leftPos(3, 0);
pair<int, int> rightPos(3, 2);

pair<int, int> getPos(const int num)
{
	if (num == 1)
	{
		return pair<int, int>(0, 0);
	}
	else if (num == 2)
	{
		return pair<int, int>(0, 1);
	}
	else if (num == 3)
	{
		return pair<int, int>(0, 2);
	}
	else if (num == 4)
	{
		return pair<int, int>(1, 0);
	}
	else if (num == 5)
	{
		return pair<int, int>(1, 1);
	}
	else if (num == 6)
	{
		return pair<int, int>(1, 2);
	}
	else if (num == 7)
	{
		return pair<int, int>(2, 0);
	}
	else if (num == 8)
	{
		return pair<int, int>(2, 1);
	}
	else if (num == 9)
	{
		return pair<int, int>(2, 2);
	}
	else// if (num == 0)
	{
		return pair<int, int>(3, 1);
	}
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	for (const auto& d : numbers)
	{
		//왼손
		if (d == 1 || d == 4 || d == 7)
		{
			leftPos = getPos(d);
			answer += "L";
		}
		//오른손
		else if (d == 3 || d == 6 || d == 9)
		{
			rightPos = getPos(d);
			answer += "R";
		}
		//가까운 손
		else
		{
			pair<int, int> tempPos = getPos(d);
			int leftDist = abs(tempPos.first - leftPos.first) + abs(tempPos.second - leftPos.second);
			int rightDist = abs(tempPos.first - rightPos.first) + abs(tempPos.second - rightPos.second);
			if (leftDist == rightDist)
			{
				if (hand == "left")
				{
					leftPos = tempPos;
					answer += "L";
				}
				else //(hand == "right")
				{
					rightPos = tempPos;
					answer += "R";
				}
			}
			else if (leftDist < rightDist)
			{
				leftPos = tempPos;
				answer += "L";
			}
			else// if (leftDist > rightDist)
			{
				rightPos = tempPos;
				answer += "R";
			}
		}
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> numbers{ 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
	string hand = "right";
	cout << solution(numbers, hand) << "\n";
	return 0;
}