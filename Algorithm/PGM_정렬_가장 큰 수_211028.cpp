#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
	string answer = "";
	sort(numbers.begin(), numbers.end(), [](const int a, const int b) {
		return to_string(a).append(to_string(b)) > to_string(b).append(to_string(a));
		});
	for (const int d : numbers) {
		answer.append(to_string(d));
	}
	return ((answer[0] == '0') ? "0" : answer);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//vector<int> numbers{ 3, 30, 34, 5, 9 };
	vector<int> numbers{ 1, 10, 100, 1000 };
	//vector<int> numbers{ 979, 97, 978, 81, 818, 817 };
	cout << solution(numbers) << "\n";
	return 0;
}