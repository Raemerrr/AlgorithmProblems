#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string str;
	int M;
	cin >> str;
	cin >> M;
	list<char> l(str.begin(), str.end());
	auto it = l.end();
	while (M--)
	{
		char c = ' ';
		cin >> c;
		if (c == 'P')
		{
			char cc = ' ';
			cin >> cc;
			l.insert(it, cc);
		}
		else if (c == 'L')
		{
			if (it != l.begin())
			{
				it--;
			}
		}
		else if (c == 'D')
		{
			if (it != l.end())
			{
				it++;
			}
		}
		else if (c == 'B')
		{
			if (it != l.begin())
			{
				//삭제 후에도 내가 가리키는 위치는 그대로다.
				auto tempIt = it;
				l.erase(--tempIt);
			}
		}
	}
	cout << string(l.begin(), l.end()) << "\n";
	return 0;
}