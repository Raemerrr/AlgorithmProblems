#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0; cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		map<int, int> minMap;
		map<int, int, greater<int>> maxMap;
		int loop = 0; cin >> loop;
		for (int i = 0; i < loop; i++)
		{
			char order = ' '; int num = 0;
			cin >> order >> num;
			if (order == 'I')
			{
				minMap[num]++;
				maxMap[num]++;
			}
			else
			{
				//ÃÖ´ñ°ª »©±â
				if (num == 1)
				{
					if (!maxMap.empty())
					{
						int maxVal = (*maxMap.begin()).first;
						maxMap[maxVal]--;
						minMap[maxVal]--;
						if (maxMap[maxVal] == 0)
						{
							maxMap.erase(maxVal);
							minMap.erase(maxVal);
						}
					}
				}
				//ÃÖ¼Ú°ª »©±â
				else
				{
					if (!minMap.empty())
					{
						int minVal = (*minMap.begin()).first;
						minMap[minVal]--;
						maxMap[minVal]--;
						if (minMap[minVal] == 0)
						{
							minMap.erase(minVal);
							maxMap.erase(minVal);
						}
					}
				}
			}
		}
		if (maxMap.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			cout << (*maxMap.begin()).first << " " << (*minMap.begin()).first << "\n";
		}
	}
	return 0;
}