#include <iostream>
#include <vector>

using namespace std;

int N, num;
long long answer;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	while (N--) {
		cin >> num;
		while (!v.empty() && v.back() <= num) {
			v.pop_back();
		}
		v.push_back(num);
		answer += v.size() - 1;
	}
	cout << answer << "\n";
	return 0;
}