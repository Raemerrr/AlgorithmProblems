#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int N, K, answer;
vector<vector<int>> board;
vector<vector<int>> idx;
vector<int> parent;
deque<pair<int, int>> dq;
//문명들의 초기 위치
vector<pair<int, int>> initPos;
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

bool checkRange(const int y, const int x) {
	if (x > 0 && x <= N && y > 0 && y <= N) { return true; }
	return false;
}

int findParent(const int key) {
	if (parent[key] == key)
	{
		return key;
	}
	return parent[key] = findParent(parent[key]);
}

void merge(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a == b)
	{
		return;
	}
	//병합 시 우선 순위가 없음 - 한쪽으로 몰아주기
	parent[b] = a;
}

void bfs_merge() {
	for (int i = 0, size = dq.size(); i < size; i++) {
		pair<int, int> front = dq[i];
		for (int d = 0; d < 4; d++)
		{
			int tempY = front.first + dy[d];
			int tempX = front.second + dx[d];
			//idx[tempY][tempX] > 0 - 주변(상,하,좌,우) 문명이 있다면 문명 합치기
			if (checkRange(tempY, tempX) && idx[tempY][tempX] > 0)
			{
				merge(idx[front.first][front.second], idx[tempY][tempX]);
			}
		}
	}
}

void bfs() {
	for (int i = 0, size = dq.size(); i < size; i++) {
		pair<int, int> front = dq.front();
		dq.pop_front();
		for (int d = 0; d < 4; d++)
		{
			int tempY = front.first + dy[d];
			int tempX = front.second + dx[d];
			//idx[tempY][tempX] == 0 - 주변(상,하,좌,우) 미개지역이라면 문명 전파
			if (checkRange(tempY, tempX) && idx[tempY][tempX] == 0)
			{
				//idx 번호를 전파한 문명의 idx를 따라감 - 시간 절약에 큰 도움
				idx[tempY][tempX] = idx[front.first][front.second];
				dq.emplace_back(tempY, tempX);
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	board.assign(N + 1, vector<int>(N + 1, 0));
	idx.assign(N + 1, vector<int>(N + 1, 0));
	parent.assign(((N + 1)*(N + 1)), 0);
	//1부터 인덱스 부여하기위해
	for (int i = 1; i <= K; i++)
	{
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;
		idx[num1][num2] = i;
		parent[i] = i;
		board[num1][num2] = i;
		dq.emplace_back(num1, num2);
		initPos.emplace_back(num1, num2);
	}

	while (true)
	{
		//문명 합치기
		bfs_merge();
		//종료 체크 - 처음 문명의 parent가 모두 같아지면 종료
		bool flag = true;
		for (int i = 0; i < initPos.size() - 1; i++) {
			if (findParent(idx[initPos[i].first][initPos[i].second]) !=
				findParent(idx[initPos[i + 1].first][initPos[i + 1].second])
				)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			break;
		}
		//문명 전파
		bfs();
		answer++;
	}
	cout << answer << "\n";
	return 0;
}