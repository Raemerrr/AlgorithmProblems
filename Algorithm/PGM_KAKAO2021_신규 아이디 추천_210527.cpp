#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

string solution(string new_id) {
	// 1�ܰ� new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
	transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
	// 2�ܰ� new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
	regex re1(R"([^a-z0-9\-_\.])");
	new_id = regex_replace(new_id, re1, "");
	// 3�ܰ� new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
	regex re2(R"(\.{2,})");
	new_id = regex_replace(new_id, re2, ".");
	// 4�ܰ� new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
	if (!new_id.empty() && new_id.front() == '.') new_id.erase(new_id.begin());
	// 5�ܰ� new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
	if (!new_id.empty() && new_id.back() == '.') new_id.pop_back();
	if (new_id.empty()) new_id.push_back('a');
	// 6�ܰ� new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����մϴ�.
	//       ���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
	if (new_id.size() > 15) {
		for (int i = 0, size = new_id.size() - 15; i < size; i++) { new_id.pop_back(); }
		if (!new_id.empty() && new_id.back() == '.') new_id.pop_back();
	}
	// 7�ܰ� new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.
	if (!new_id.empty()) {
		char c = new_id.back();
		while (new_id.size() < 3)
		{
			new_id.push_back(c);
		}
	}
	return new_id;
}

int main() {
	//string new_id = "...!@BaT#*..y.abcdefghijklm";
	string new_id = "abcdefghijklmn.p";
	cout << solution(new_id) << "\n";
	return 0;
}