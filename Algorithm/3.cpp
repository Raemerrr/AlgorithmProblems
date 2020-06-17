#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

vector<int> proc(vector<int> scores, vector<int> alice)
{
	vector<int> ans;
	set<int, greater<int>> s(scores.begin(), scores.end());
	vector<int> v;
	for (const auto a : alice)
	{
		int rank = 1;
		for (auto d : s)
		{
			if (a >= d)
			{
				break;
			}
			rank++;
		}
		ans.emplace_back(rank);
	}
	return ans;
}


//vector<int> proc(vector<int> score, vector<int> alice)
//{
//	vector<int> ans;
//	for (int i = 0; i < alice.size(); i++)
//	{
//		int rank = 1;
//		multiset<int, greater<int>> ms(score.begin(), score.end());
//		ms.emplace(alice[i]);
//		int curr = *(ms.begin());
//		for (auto d : ms) 
//		{
//			if (d != curr)
//			{
//				rank++;
//			}
//			if (d == alice[i])
//			{
//				ans.emplace_back(rank);
//				break;
//			}
//			curr = d;
//		}
//	}
//	return ans;
//}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//vector<int> v{ 100,100,50,40,40,20,10 };
	//vector<int> a{ 5,25,50,120};
	vector<int> v{ 100,90,90,80,75,60 };
	vector<int> a{ 50,65,77,90,102 };
	for (auto d : proc(v, a)) 
	{
		cout << d << " ";
	}
	cout << "\n";

	return 0;
}