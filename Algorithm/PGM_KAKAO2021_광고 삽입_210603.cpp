#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

typedef long long LL;

int to_integer(string s) {
	replace(s.begin(), s.end(), ':', ' ');
	stringstream in(s);
	int hh = 0, mm = 0, ss = 0; in >> hh >> mm >> ss;
	return (hh * 3600) + (mm * 60) + (ss);
}

string to_hhmmss(int time) {
	string s;
	string hh = to_string(time / 3600);
	while (hh.size() < 2)
	{
		hh = '0' + hh;
	}
	s += hh + ":";
	time %= 3600;
	string mm = to_string(time / 60);
	while (mm.size() < 2)
	{
		mm = '0' + mm;
	}
	s += mm + ":";
	time %= 60;
	string ss = to_string(time);
	while (ss.size() < 2)
	{
		ss = '0' + ss;
	}
	s += ss;
	return s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
	string answer = "";
	int n = to_integer(play_time), m = to_integer(adv_time);
	vector<pair<int, int>> v;
	for (auto s : logs) {
		for (auto& i : s) if (i == '-') i = ' ';
		stringstream in(s);
		string t1, t2; in >> t1 >> t2;
		v.push_back({ to_integer(t1), to_integer(t2) });
	}
	//prefix-sum
	vector<LL> pSum(n + 1);
	for (const pair<int, int>& d : v) pSum[d.first]++, pSum[d.second]--;
	for (int i = 1; i <= n; i++) pSum[i] += pSum[i - 1];
	for (int i = 1; i <= n; i++) pSum[i] += pSum[i - 1];

	//query
	LL maxVal = 0, time = 0;
	for (int i = 0; i + m <= n; i++)
	{
		LL t = pSum[i + m - 1] - (i ? pSum[i - 1] : 0);
		if (maxVal < t) {
			maxVal = t;
			time = i;
		}
	}
	return to_hhmmss(time);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string play_time = "02:03:55";
	//string play_time = "50:00:00";
	string adv_time = "00:14:15";
	//string adv_time = "50:00:00";
	vector<string> logs{ "01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30" };
	//vector<string> logs{ "15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45" };
	solution(play_time, adv_time, logs);
	cout << "\n";
	return 0;
}