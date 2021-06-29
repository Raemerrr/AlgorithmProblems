#include <iostream>
#include <map>

using namespace std;

int N;
map<char, pair<char, char>> m;

void preOrder(const char root) {
	if (root == '.') return;
	cout << root;
	preOrder(m[root].first);
	preOrder(m[root].second);
}

void inOrder(const char root) {
	if (root == '.') return;
	inOrder(m[root].first);
	cout << root;
	inOrder(m[root].second);
}

void postOrder(const char root) {
	if (root == '.') return;
	postOrder(m[root].first);
	postOrder(m[root].second);
	cout << root;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char root = ' ', Left = ' ', Right = ' ';
		cin >> root >> Left >> Right;
		m[root].first = Left; m[root].second = Right;
	}
	preOrder('A'); cout << "\n";
	inOrder('A'); cout << "\n";
	postOrder('A'); cout << "\n";
	return 0;
}