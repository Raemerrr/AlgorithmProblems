#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> gems) {
	//보석 별 위치를 기억하는 변수
	map<string, vector<int>> m;
	//구간 별 보석의 최종 위치
	vector<int> temp;
	set<string> s(gems.begin(), gems.end());
	//보석함의 중복을 제거한 수
	int total = s.size();
	int cnt = 0;
	//주어진 보석 수 보다 구간이 클 순 없다. (초기 값 = 최대 값)
	int len = gems.size();
	vector<pair<int, pair<int, int>>> answer;
	//Loop 중 더 짧은 구간이 있을 수 있다.
	for (int i = 0; i < gems.size(); i++)
	{
		//구간에 나왔던 보석이 아니라면 카운트
		if (m[gems[i]].empty())
		{
			cnt++;
		}
		//매번 방문하는 보석 마다 최종 위치 기억
		m[gems[i]].push_back(i + 1);
		//구간이 완성 되었다면
		if (cnt == total)
		{
			//보석의 최종 위치들을 한 곳에 모아 구간을 추린다.
			for (const auto& d : m)
			{
				temp.push_back(d.second[d.second.size() - 1]);
			}
			sort(temp.begin(), temp.end());
			int _start = temp[0];
			int _end = temp[temp.size() - 1];
			int tLen = _end - _start + 1;
			len = len < tLen ? len : tLen;
			//초기화
			m.clear();
			temp.clear();
			cnt = 0;
			//더 짧은 구간을 찾기 위해
			i = _start - 1;
			answer.emplace_back(len, make_pair(_start, _end));
		}
	}
	//가장 짧은 구간 중 _start가 작은 구간을 답으로 도출하기 위한 정렬
	sort(answer.begin(), answer.end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b)
	{
		//구간의 길이가 같다면 작은 _start 순으로 정렬
		if (a.first == b.first)
		{
			return a.second.first < b.second.first;
		}
		//구간의 길이가 다르다면 구간의 길이 순으로 정렬
		else
		{
			return a.first < b.first;
		}
	});
	return vector<int>{answer[0].second.first, answer[0].second.second};
}

/*
프로그래머스 사이트는 main()함수를 입력받지 않습니다.
예제를 실행 하기 위해 입력해놓은 것입니다.
*/
int main()
{
	/*
	["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]	[3, 7]
	["AA", "AB", "AC", "AA", "AC"]	[1, 3]
	["XYZ", "XYZ", "XYZ"]	[1, 1]
	["ZZZ", "YYY", "NNNN", "YYY", "BBB"]	[1, 5]
	*/
	vector<string> v{ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
	//vector<string> v{ "AA", "AB", "AC", "AA", "AC" };
	//vector<string> v{ "XYZ", "XYZ", "XYZ" };
	//vector<string> v{ "ZZZ", "YYY", "NNNN", "YYY", "BBB" };
	cout << "[";
	for (const auto& d : solution(v))
	{
		cout << d << ":";
	}
	cout << "]\n";
	return 0;
}