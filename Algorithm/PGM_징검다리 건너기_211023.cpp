#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 200000001;
	multiset<int, greater<int>> ms;
	for (int i = 0; i < k - 1; i++) ms.insert(stones[i]);
	for (int i = k - 1; i < stones.size(); i++)
	{
		ms.insert(stones[i]);
		answer = min(answer, *ms.begin());
		ms.erase(ms.find(stones[i - (k - 1)]));
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	vector<int> stones{ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
	int k = 3;
	cout << solution(stones, k) << "\n";
	cin.tie(0);
	return 0;
}