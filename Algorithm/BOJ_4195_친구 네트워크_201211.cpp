#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<string, string> parent;
map<string, int> parentRank;

string findParent(string& key) {
	if (key == parent[key])
	{
		return key;
	}
	return parent[key] = findParent(parent[key]);
}

void merge(string& str1, string& str2) {
	string p1 = findParent(str1);
	string p2 = findParent(str2);

	if (p1 == p2)
	{
		cout << parentRank[p1] << "\n";
		return;
	}

	if (parentRank[p1] < parentRank[p2])
	{
		swap(p1, p2);
	}

	parent[p2] = p1;
	parentRank[p1] += parentRank[p2];
	parentRank[p2] = 0;
	cout << parentRank[p1] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		int loop = 0;
		cin >> loop;
		for (int i = 0; i < loop; i++)
		{
			string str1, str2;
			cin >> str1 >> str2;
			if (!parent.count(str1))
			{
				parent[str1] = str1;
				parentRank[str1] = 1;
			}
			if (!parent.count(str2))
			{
				parent[str2] = str2;
				parentRank[str2] = 1;
			}
			merge(str1, str2);
		}
		parent.clear();
		parentRank.clear();
	}
	return 0;
}