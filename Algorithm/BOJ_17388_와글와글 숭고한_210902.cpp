#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> m{ {"Soongsil", 0},{"Korea", 0},{"Hanyang", 0} };

int sum, minVal = 101;
string minKey;

int main() {
	cin >> m["Soongsil"] >> m["Korea"] >> m["Hanyang"];
	for (const pair<string, int>& d : m) {
		sum += d.second;
		if (d.second < minVal)
		{
			minKey = d.first;
			minVal = d.second;
		}
	}
	cout << ((100 <= sum) ? "OK" : minKey) << "\n";
	return 0;
}