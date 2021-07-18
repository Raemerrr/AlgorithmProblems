#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;

int dfs(string& S, int idx) {
	int cnt = 0;
	for (int i = idx; i < S.size(); i++) {
		if (S[i] == '(' && !visited[i]) {
			visited[i] = true;
			int num = S[i - 1] - '0';
			cnt--;
			cnt += num * dfs(S, i + 1);
		}
		else if (S[i] == ')' && !visited[i]) {
			visited[i] = true;
			return cnt;
		}
		else if (!visited[i]) {
			visited[i] = true;
			cnt++;
		}
	}
	return cnt;
}

int main() {
	string S, answer; cin >> S;
	visited.assign(S.size(), false);
	cout << dfs(S, 0) << endl;
	return 0;
}