#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string A, B, answer;
int add;

void proc(string& str) {
	if (!str.empty())
	{
		for (int i = 0, size = str.size(); i < size; i++)
		{
			int num = str.back() - '0'; str.pop_back();
			int sum = num + add;
			answer = to_string(sum % 10) + answer;
			add = sum / 10;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B;
	for (int i = 0, size = min(A.size(), B.size()); i < size; i++)
	{
		int aNum = A.back() - '0'; A.pop_back();
		int bNum = B.back() - '0'; B.pop_back();
		int sum = aNum + bNum + add;
		answer = to_string(sum % 10) + answer;
		add = sum / 10;
	}
	proc(A), proc(B);
	if (A.empty() && B.empty() && add > 0)
	{
		answer = to_string(add) + answer;
	}
	cout << answer << "\n";
	return 0;
}