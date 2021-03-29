#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

string order, str;
int num;
deque<string> dq;
bool reverseFlag, errorFlag;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> test_case;
	while (test_case--)
	{
		reverseFlag = errorFlag = false;
		dq.clear();
		cin >> order >> num >> str;
		//'[' ���� ����
		str.erase(str.begin());
		//']' ���� ����
		str.pop_back();
		//',' ���� ���� �и�
		istringstream ss(str);
		string temp;
		while (getline(ss, temp, ',')) {
			dq.push_back(temp);
		}
		for (const char d : order) {
			if (d == 'R')
			{
				reverseFlag = !reverseFlag;
			}
			else if (d == 'D')
			{
				if (dq.empty())
				{
					errorFlag = true;
					break;
				}
				if (reverseFlag)
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
			}
		}
		if (errorFlag)
		{
			cout << "error\n";
		}
		else
		{
			cout << "[";
			for (int i = 0, size = dq.size(); i < size; i++)
			{
				if (reverseFlag)
				{
					cout << dq.back();
					dq.pop_back();
				}
				else
				{
					cout << dq.front();
					dq.pop_front();
				}
				//������ �� �ڿ��� ǥ������ �ʴ´�.
				if (i < size - 1)
				{
					cout << ",";
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}