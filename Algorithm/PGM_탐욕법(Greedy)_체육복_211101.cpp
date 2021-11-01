#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	// 여벌 체육복을 가져온 학생이 체육복을 도난당했을 경우
	set<int> lostSet(lost.begin(), lost.end()), reserveSet;
	for (const int d : reserve) {
		if (lostSet.count(d))
			lostSet.erase(d);
		else
			reserveSet.insert(d);
	}
	vector<int> sub{ -1, 0, 1 };
	int answer = n - lostSet.size();
	for (const int d : lostSet) {
		if (reserveSet.empty()) break;
		for (const int s : sub) {
			if (reserveSet.count(d + s))
			{
				reserveSet.erase(d + s);
				answer++;
				break;
			}
		}
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//int n = 5;
	//vector<int> lost{ 2, 4 };
	//vector<int> reserve{ 1, 3, 5 };
	/*int n = 10;
	vector<int> lost{ 5,4,3,2,1 };
	vector<int> reserve{ 3,1,2,5,4 };*/

	int n = 5;
	vector<int> lost{ 3,5 };
	vector<int> reserve{ 2,4 };

	/*int n = 5;
	vector<int> lost{ 2,4 };
	vector<int> reserve{ 3,5 };*/
	cout << solution(n, lost, reserve) << "\n";
	return 0;
}