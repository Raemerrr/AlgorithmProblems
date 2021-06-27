#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S, D, answer;
vector<vector<int>> v;
vector<int> depth;
vector<bool> visited;

void dfs(const int Cur) {
	for (const int Next : v[Cur]) {
		if (!visited[Next])
		{
			visited[Next] = true;
			dfs(Next);
			visited[Next] = false;
			depth[Cur] = max(depth[Cur], depth[Next] + 1);
		}
	}
}

void search(const int Cur) {
	for (const int Next : v[Cur]) {
		if (!visited[Next] && depth[Next] >= D)
		{
			//방문++
			answer++;
			visited[Next] = true;
			search(Next);
			//복귀++
			answer++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> S >> D; S--;
	v.assign(N, vector<int>());
	depth.assign(N, 0);
	for (int i = 0; i < N - 1; i++)
	{
		int y = 0, x = 0; cin >> y >> x; y--, x--;
		v[y].push_back(x);
		v[x].push_back(y);
	}
	//리프 노드로부터 현재 노드의 depth 구하기
	visited.assign(N, false);
	visited[S] = true;
	depth[S] = 0;
	dfs(S);

	//현재 노드의 depth가 D(힘)값 이상인 경우에만 탐색
	visited.assign(N, false);
	visited[S] = true;
	search(S);
	cout << answer << "\n";
	return 0;
}