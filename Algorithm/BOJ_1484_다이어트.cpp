#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

int N;
ULL s = 1, e = 1;
bool flag;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (true)
	{
		ULL eNum = e * e;
		ULL sNum = s * s;
		//종료문 - 가장 인접한 제곱수 끼리의 차가 N보다 크면 더 이상 답을 구할 수 없음!
		if (e - s == 1 && eNum - sNum > N) { break; }
		if (eNum - sNum < N)
		{
			e++;
		}
		else if (eNum - sNum == N)
		{
			flag = true;
			cout << e << "\n";
			e++;
		}
		else
		{
			s++;
		}
	}
	if (!flag)
	{
		cout << "-1\n";
	}
	return 0;
}