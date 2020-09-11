#include <iostream>
#include <vector>

using namespace std;
int L, P, V;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int caseNum = 1;
	while (true)
	{
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
		{
			break;
		}
		int flag = V % P < L ? V % P : L;
		cout << "Case " << caseNum << ": " << V / P * L + flag << "\n";
		caseNum++;
	}
	return 0;
}