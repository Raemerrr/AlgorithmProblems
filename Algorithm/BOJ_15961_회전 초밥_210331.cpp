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
	//k������ ������ �̸� ä�����´�.
	for (int i = 0; i < k; i++)
	{
		if (arr[v[i]] == 0)
		{
			cnt++;
		}
		dq.push_back(v[i]);
		arr[v[i]]++;
	}
	//���� ��ġ
	s = 0;
	//�� ��ġ
	e = k - 1;
	while (s < N)
	{
		//���� �ʹ� ���� Ȯ��
		int tCnt = (arr[c] > 0) ? cnt : cnt + 1;
		ans = (ans > tCnt) ? ans : tCnt;
		e++;
		s++;
		//���� ���� ��ġ�� �ʹ� ���� 0�� �ʹ����� ���� �ϵ���
		if (e == N)
		{
			e = 0;
		}
		//�ڿ� ���� �߰��ϴ� �۾�
		if (arr[v[e]] == 0)
		{
			cnt++;
		}
		arr[v[e]]++;
		dq.push_back(v[e]);
		//�տ� ���� ���� �۾�
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