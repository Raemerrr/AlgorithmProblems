#include <iostream>
#include <deque>
#include <map>

using namespace std;

deque<int> v;
deque<int> slice;
int N, d, k, c, add, answer;
map<int, int> m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> d >> k >> c;
	v = deque<int>(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < k; i++)
	{
		m[v[i]]++;
		slice.push_back(v[i]);
	}
	if (!m.count(c))
	{
		add = 1;
	}
	//처음 slice에 담은 내용이 가장 클 경우가 있다.
	answer = m.size() + add;
	for (int i = k; i < N + k; i++)
	{
		add = 0;
		//slice의 첫 값을 삭제
		m[slice[0]]--;
		if (m[slice[0]] < 1)
		{
			m.erase(slice[0]);
		}
		slice.pop_front();
		m[v[i % N]]++;
		slice.push_back(v[i % N]);
		if (!m.count(c))
		{
			add = 1;
		}
		answer = answer > m.size() + add ? answer : m.size() + add;
	}
	cout << answer << "\n";
	return 0;
}