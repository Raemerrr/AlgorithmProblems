//핵심 stack이 비었다면 데이터를 쌓고 그 다음 들어오는 데이터와 같다면 pop_back 다르다면 쌓기
//마지막에 stack이 비어있지 않다면, 그 단어는 잘못된 단어
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N, ans;
vector<string> v;

void Func()
{
	//입력 받은 string을 순차 적으로 탐색한다.
	for (auto& data : v)
	{
		//stack 구조를 이용해 해결한다.
		vector<char> stack;
		while (!data.empty())
		{
			char front = data[0];
			if (stack.empty())
			{
				stack.emplace_back(front);
			}
			else
			{
				if (stack[stack.size() - 1] == front)
				{
					//나중에 들어온 데이터를 먼저 비교해 내보내기 위해 stack사용
					stack.pop_back();
				}
				else
				{
					stack.emplace_back(front);
				}
			}
			//erase는 begin()부터 하기때문에 성능상.. 큰 무리가 없다..?
			data.erase(data.begin());
		}
		if (stack.empty())
		{
			ans++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v = vector<string>(N, "");
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	Func();
	cout << ans << "\n";
	return 0;
}