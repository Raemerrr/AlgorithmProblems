#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int arr[3000001];
int sushi[3001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, d, k, c; cin >> n >> d >> k >> c;
	for (int i = 1; i <= n; ++i) cin >> arr[i];

	deque<int> dq;
	int cnt = 0, ans = 0;
	for (int i = 1; i <= k; ++i) {
		if (!sushi[arr[i]]) cnt++;
		sushi[arr[i]]++; dq.push_back(arr[i]);
	}

	for (int s = 1, e = k + 1; s <= n; ++s, ++e) {
		if (e == n + 1) e = 1;
		ans = max(ans, sushi[c] ? cnt : cnt + 1);

		sushi[arr[s]]--; dq.pop_front();
		if (!sushi[arr[s]]) cnt--;

		if (!sushi[arr[e]]) cnt++;
		sushi[arr[e]]++; dq.push_back(arr[e]);
	}

	cout << ans;
}