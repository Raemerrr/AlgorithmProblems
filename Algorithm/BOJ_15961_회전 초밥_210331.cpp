#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, d, k, c;
vector<int> v;
int s, e, cnt, ans;
vector<int> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> d >> k >> c;
	v.assign(N, 0);
	arr.assign(3001, 0);
	deque<int> dq;
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	//k까지의 내용을 미리 채워놓는다.
	for (int i = 0; i < k; i++)
	{
		if (arr[v[i]] == 0)
		{
			cnt++;
		}
		dq.push_back(v[i]);
		arr[v[i]]++;
	}
	//시작 위치
	s = 0;
	//끝 위치
	e = k - 1;
	while (s < N)
	{
		//쿠폰 초밥 포함 확인
		int tCnt = (arr[c] > 0) ? cnt : cnt + 1;
		ans = (ans > tCnt) ? ans : tCnt;
		e++;
		s++;
		//가장 끝에 위치한 초밥 이후 0번 초밥으로 접근 하도록
		if (e == N)
		{
			e = 0;
		}
		//뒤에 것을 추가하는 작업
		if (arr[v[e]] == 0)
		{
			cnt++;
		}
		arr[v[e]]++;
		dq.push_back(v[e]);
		//앞에 것을 빼는 작업
		arr[dq.front()]--;
		if (arr[dq.front()] == 0)
		{
			cnt--;
		}
		dq.pop_front();
	}
	cout << ans << "\n";
	return 0;
}