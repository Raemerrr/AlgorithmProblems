#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<string>> pad;
string lChar = "*";
string rChar = "#";
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,-1,0,1 };

pair<int, int> getPos(const string& c) {
	if (c == "1") {
		return pair<int, int>(0, 0);
	}
	else if (c == "2") {
		return pair<int, int>(0, 1);
	}
	else if (c == "3") {
		return pair<int, int>(0, 2);
	}
	else if (c == "4") {
		return pair<int, int>(1, 0);
	}
	else if (c == "5") {
		return pair<int, int>(1, 1);
	}
	else if (c == "6") {
		return pair<int, int>(1, 2);
	}
	else if (c == "7") {
		return pair<int, int>(2, 0);
	}
	else if (c == "8") {
		return pair<int, int>(2, 1);
	}
	else if (c == "9") {
		return pair<int, int>(2, 2);
	}
	else if (c == "*") {
		return pair<int, int>(3, 0);
	}
	else if (c == "0") {
		return pair<int, int>(3, 1);
	}
	else { //if(c == "#"){
		return pair<int, int>(3, 2);
	}
}

bool checkRange(const int y, const int x) {
	if (y >= 0 && y < 4 && x >= 0 && x < 3) {
		return true;
	}
	return false;
}

int bfs(const pair<int, int>& start, const pair<int, int>& target) {
	int cnt = 0;
	vector<vector<bool>> visited(4, vector<bool>(3, false));
	queue<pair<int, int>> q;
	q.push(start);
	while (!q.empty()) {
		for (int z = 0, size = q.size(); z < size; z++) {
			pair<int, int> front = q.front();
			q.pop();
			visited[front.first][front.second] = true;
			if (front.first == target.first && front.second == target.second) {
				while (!q.empty()) { q.pop(); }
				break;
			}
			for (int i = 0; i < 4; i++) {
				int tempY = front.first + dy[i];
				int tempX = front.second + dx[i];
				if (checkRange(tempY, tempX) && !visited[tempY][tempX]) {
					visited[tempY][tempX] = true;
					q.emplace(tempY, tempX);
				}
			}
		}
		cnt++;
	}
	return cnt;
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	pad = vector<vector<string>>{
		{"1","2","3"},
		{"4","5","6"},
		{"7","8","9"},
		{"*","0","#"}
	};
	for (const int d : numbers) {
		if (d == 1 || d == 4 || d == 7) {
			answer += "L";
			lChar = to_string(d);
		}
		else if (d == 3 || d == 6 || d == 9) {
			answer += "R";
			rChar = to_string(d);
		}
		else {
			int lCnt = bfs(getPos(lChar), getPos(to_string(d)));
			int rCnt = bfs(getPos(rChar), getPos(to_string(d)));
			if (lCnt < rCnt) {
				answer += "L";
				lChar = to_string(d);
			}
			else if (lCnt > rCnt) {
				answer += "R";
				rChar = to_string(d);
			}
			else {
				if (hand == "right") {
					answer += "R";
					rChar = to_string(d);
				}
				else {
					answer += "L";
					lChar = to_string(d);
				}
			}
		}
	}
	return answer;
}

int main() {
	vector<int> numbers{ 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
	string hand = "right";
	//vector<int> numbers{ 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };
	//string hand = "left";
	//vector<int> numbers{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	//string hand = "right";
	cout << solution(numbers, hand) << "\n";
	return 0;
}