#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, H, cnt, minVal = 987654321;
//석순 배열
vector<int> bottomArr;
//종유석 배열
vector<int> topArr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> H;
	bottomArr = topArr = vector<int>(N / 2, 0);
	for (int i = 0; i < N / 2; i++)
	{
		cin >> bottomArr[i] >> topArr[i];
	}
	sort(bottomArr.begin(), bottomArr.end());
	sort(topArr.begin(), topArr.end());
	for (int i = 1; i <= H; i++)
	{
		// 해당 구간에 겹치는 '석순'의 수
		int temp = bottomArr.size() - (lower_bound(bottomArr.begin(), bottomArr.end(), i) - bottomArr.begin());
		// 해당 구간에 겹치는 '종유석'의 수 
		// *주의* : H - i
		temp += topArr.size() - (upper_bound(topArr.begin(), topArr.end(), H - i) - topArr.begin());
		if (temp < minVal)
		{
			minVal = temp;
			cnt = 1;
		}
		else if (minVal == temp)
		{
			cnt++;
		}
	}
	cout << minVal << " " << cnt << "\n";
	return 0;
}