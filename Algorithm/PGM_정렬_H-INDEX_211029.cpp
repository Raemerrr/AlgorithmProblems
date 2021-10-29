#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.rbegin(), citations.rend());
	for (int i = 0; i < citations.size(); i++)
	{
		if (i + 1 <= citations[i])
		{
			answer++;
		}
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> citations{ 3, 0, 6, 1, 5 };
	cout << solution(citations) << "\n";
	return 0;
}