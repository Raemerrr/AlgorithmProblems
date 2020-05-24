#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;
int N, MAX = -1000000000, MIN = 1000000000;
//입력 수 저장
vector<int> v;
//연산자 저장 
vector<char> c;
//연산자 조합 저장
set<vector<char>> s;
char cArr[4]{ '+','-','*','/' };
//임시 연산자 조합
vector<char> tempArr;
//연산자 조합 시 재방문 판단
vector<bool> visited;

//연산자 조합 구하기
void Combi()
{
	if (tempArr.size() == N - 1)
	{
		s.emplace(tempArr);
	}
	else
	{
		for (int i = 0; i < c.size(); i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				tempArr.emplace_back(c[i]);
				Combi();
				tempArr.pop_back();
				visited[i] = false;
			}
		}
	}
}

//실행부
void Proc()
{
	for (const auto& d : s)
	{
		int i = 1;
		int res = v[0];
		for (const auto& t : d)
		{
			if (t == '+')
			{
				res = res + v[i];
			}
			else if (t == '-')
			{
				res = res - v[i];
			}
			else if (t == '*')
			{
				res = res * v[i];
			}
			// t == '/'
			else
			{
				if (res < 0)
				{
					//양수로 바꾸고
					res *= -1;
					res = ((res / v[i]) * -1);
				}
				else
				{
					res = (res / v[i]);
				}
			}
			i++;
		}
		MAX = (MAX > res) ? MAX : res;
		MIN = (MIN < res) ? MIN : res;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v = vector<int>(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	//기호는 4가지
	for (int i = 0; i < 4; i++)
	{
		int num = 0;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			//그에 맞는 기호를 넣어 조합하려고...
			c.emplace_back(cArr[i]);
		}
	}
	visited = vector<bool>(c.size(), false);
	Combi();
	Proc();
	cout << MAX << "\n" << MIN << "\n";
	return 0;
}