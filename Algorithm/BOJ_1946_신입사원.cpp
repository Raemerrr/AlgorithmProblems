#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	for (int t = 0; t < test_case; t++)
	{
		int N = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int num1 = 0, num2 = 0;
			cin >> num1 >> num2;
			v.emplace_back(num1, num2);
		}
		//서류 점수 기준으로 정렬
		sort(v.begin(), v.end());
		//이미 서류 1등은 포함
		int ans = 1;
		//서류 1등의 면접 점수를 가지고 비교를 시작
		int comp = v[0].second;
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i].second < comp)
			{
				comp = v[i].second;
				ans++;
			}
		}
		cout << ans << "\n";
		v.clear();
	}
	return 0;
}