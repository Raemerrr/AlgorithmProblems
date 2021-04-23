#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
	set<string> ss(gems.begin(), gems.end());
	map<string, int> m;
	int s = 0, e = 0, cnt = ss.size(), range = gems.size();
	vector<int> answer{ 0, range - 1 };
	m[gems[s]]++;
	while (true) {
		if (m.size() == cnt) {
			if (answer[1] - answer[0] > e - s) {
				answer[0] = s;
				answer[1] = e;
			}
			if (s == e) break;
			else {
				m[gems[s]]--;
				if (m[gems[s]] == 0) m.erase(gems[s]);
				s++;
			}
		}
		else if (m.size() > cnt) {
			if (s + 1 >= range) break;
			else {
				m[gems[s]]--;
				if (m[gems[s]] == 0) m.erase(gems[s]);
				s++;
			}
		}
		else if (m.size() < cnt) {
			if (e + 1 >= range) break;
			else {
				m[gems[++e]]++;
			}
		}
	}
	answer[0]++;
	answer[1]++;
	return answer;
}

int main() {
	//vector<string> gems{ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
	vector<string> gems{ "AA", "AB", "AC", "AA", "AC" };
	//vector<string> gems{ "XYZ", "XYZ", "XYZ" };
	//vector<string> gems{ "ZZZ", "YYY", "NNNN", "YYY", "BBB" };
	for (auto d : solution(gems)) { cout << d << " "; }
	return 0;
}