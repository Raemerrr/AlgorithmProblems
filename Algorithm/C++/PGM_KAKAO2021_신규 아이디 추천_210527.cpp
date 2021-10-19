#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;

string solution(string new_id) {
	// 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
	transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
	// 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
	regex re1(R"([^a-z0-9\-_\.])");
	new_id = regex_replace(new_id, re1, "");
	// 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
	regex re2(R"(\.{2,})");
	new_id = regex_replace(new_id, re2, ".");
	// 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
	if (!new_id.empty() && new_id.front() == '.') new_id.erase(new_id.begin());
	// 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
	if (!new_id.empty() && new_id.back() == '.') new_id.pop_back();
	if (new_id.empty()) new_id.push_back('a');
	// 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
	//       만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
	if (new_id.size() > 15) {
		for (int i = 0, size = new_id.size() - 15; i < size; i++) { new_id.pop_back(); }
		if (!new_id.empty() && new_id.back() == '.') new_id.pop_back();
	}
	// 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
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