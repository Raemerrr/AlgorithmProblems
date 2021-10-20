#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string str;
	while (getline(cin, str)) {
		int lowerCnt = 0, upperCnt = 0, numCnt = 0, spaceCnt = 0;
		for (const char d : str) {
			if (isalpha(d))
			{
				if (isupper(d))
				{
					upperCnt++;
				}
				else
				{
					lowerCnt++;
				}
			}
			else
			{
				if (isalnum(d))
				{
					numCnt++;
				}
				else
				{
					spaceCnt++;
				}
			}
		}
		cout << lowerCnt << " " << upperCnt << " " << numCnt << " " << spaceCnt << "\n";
	}
	return 0;
}