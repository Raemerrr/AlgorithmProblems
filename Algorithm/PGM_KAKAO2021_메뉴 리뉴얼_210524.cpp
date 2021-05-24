#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	for (string& order : orders) {
		sort(order.begin(), order.end());
	}
	for (int z = 0; z < course.size(); z++)
	{
		map<string, int> m;
		vector<pair<string, int>> temp;
		for (const string& order : orders) {
			if (order.size() < course[z])
			{
				continue;
			}
			vector<int> flag;
			for (int i = 0; i < order.size() - course[z]; i++) {
				flag.push_back(0);
			}
			for (int i = 0; i < course[z]; i++) {
				flag.push_back(1);
			}
			do {
				vector<char> v;
				for (int i = 0; i < flag.size(); i++) {
					if (flag[i] == 1) {
						v.push_back(order[i]);
					}
				}
				m[string(v.begin(), v.end())]++;
			} while (next_permutation(flag.begin(), flag.end()));
			temp = vector<pair<string, int>>(m.begin(), m.end());
			sort(temp.begin(), temp.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
				if (a.second == b.second) {
					return a.first > b.first;
				}
				return a.second < b.second;
				});
		}
		if (!temp.empty())
		{
			int val = temp.back().second;
			while (temp.back().second == val && val > 1)
			{
				answer.push_back(temp.back().first);
				temp.pop_back();
			}
		}
	}
	if (!answer.empty())
	{
		sort(answer.begin(), answer.end());
	}
	return answer;
}

int main() {
	vector<string> orders{ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
	vector<int> course{ 2,3,4 };
	for (const auto& d : solution(orders, course)) {
		cout << d << "\n";
	}
	return 0;
}