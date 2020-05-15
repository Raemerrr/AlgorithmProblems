#include <iostream>

using namespace std;

int N, cnt;
int col[15 + 1];

//배치 가능한지 여부
bool promising(int i)
{
	int k = 1;
	bool flag = true;

	while (k < i && flag)
	{
		//같은 열이거나 대각선이라면 배치 못함
		if (col[i] == col[k] || abs(col[i] - col[k]) == i - k)
		{
			flag = false;
		}
		k++;
	}
	return flag;
}

void queens(int i)

{
	if (promising(i))
	{
		//판이 완성
		if (i == N)
		{
			cnt++;
		}
		else
		{
			//해당 열에 배치
			for (int j = 1; j <= N; j++)
			{
				col[i + 1] = j;
				queens(i + 1);
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	queens(0);
	cout << cnt << "\n";
	return 0;
}