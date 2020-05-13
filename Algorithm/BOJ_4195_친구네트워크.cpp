#include <iostream>
#include <map>
#include <string>

using namespace std;

int N;
map<string, string> parents;
map<string, long long> parentNodes;

string findParent(const string& key)
{
	if (parents[key] == key)
	{
		return key;
	}
	return parents[key] = findParent(parents[key]);
}

void merge(string& str1, string& str2)
{
	str1 = findParent(str1);
	str2 = findParent(str2);
	//같은 부모 속에 있다면
	if (str1 == str2)
	{
		cout << parentNodes[str2] << "\n";
		return;
	}
	if (parentNodes[str1] > parentNodes[str2])
	{
		swap(str1, str2);
	}
	parents[str1] = str2;
	parentNodes[str2] += parentNodes[str1];
	parentNodes[str1] = 0;
	cout << parentNodes[str2] << "\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			string str1 = "", str2 = "";
			cin >> str1 >> str2;
			if (parents[str1] == "")
			{
				parents[str1] = str1;
				parentNodes[str1] = 1;
			}
			if (parents[str2] == "")
			{
				parents[str2] = str2;
				parentNodes[str2] = 1;
			}
			merge(str1, str2);
		}
		parentNodes.clear();
		parents.clear();
	}
	return 0;
}