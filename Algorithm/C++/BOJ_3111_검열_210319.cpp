#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

string str, pattern;
deque<char> leftQ;
deque<char> rightQ;
int leftIdx, rightIdx, loop;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> pattern >> str;
	leftIdx = 0, rightIdx = str.size() - 1;
	while (leftIdx <= rightIdx)
	{
		while (leftIdx <= rightIdx) {
			char leftChar = str[leftIdx++];
			leftQ.push_back(leftChar);
			if (leftQ.size() >= pattern.size() && leftChar == pattern[pattern.size() - 1])
			{
				if (pattern == string(leftQ.end() - pattern.size(), leftQ.end())) {
					loop = pattern.size();
					while (loop--)
					{
						leftQ.pop_back();
					}
					break;
				}
			}
		}
		while (leftIdx <= rightIdx)
		{
			char rightChar = str[rightIdx--];
			rightQ.push_front(rightChar);
			if (rightQ.size() >= pattern.size() && rightChar == pattern[0])
			{
				if (pattern == string(rightQ.begin(), rightQ.begin() + pattern.size())) {
					loop = pattern.size();
					while (loop--)
					{
						rightQ.pop_front();
					}
					break;
				}
			}
		}
	}
	leftQ.insert(leftQ.end(), rightQ.begin(), rightQ.end());
	string ans(leftQ.begin(), leftQ.end());
	int pos = 0;
	while ((pos = ans.find(pattern)) != string::npos) {
		ans.erase(ans.begin() + pos, ans.begin() + pos + pattern.size());
	}
	cout << ans << "\n";
	return 0;
}