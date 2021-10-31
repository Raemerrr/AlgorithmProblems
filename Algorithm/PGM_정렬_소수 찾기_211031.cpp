#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

vector<bool> primeNum;

void primeNumberSieve(int number)
{
	primeNum.assign(number + 1, true);
	primeNum[0] = false, primeNum[1] = false;
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (!primeNum[i]) continue;
		for (int j = i * i; j <= number; j += i)
			primeNum[j] = false;
	}
}

int solution(string numbers) {
	int answer = 0;
	set<int> visited;
	// 입력받은 문자열로 표현 가능한 최대의 수를 구하기
	sort(numbers.rbegin(), numbers.rend());
	primeNumberSieve(stoi(numbers));
	// next_permutation 사용 전 오름차순 정렬
	sort(numbers.begin(), numbers.end());
	for (int length = 1; length <= numbers.size(); length++)
	{
		// selector생성시 오름차순으로 생성
		vector<int> selector(numbers.size() - length, 0);
		for (int i = 0; i < length; i++) selector.push_back(1);
		do {
			vector<char> v;
			for (int i = 0; i < selector.size(); i++)
			{
				if (selector[i] == 1) v.push_back(numbers[i]);
			}
			do {
				int num = stoi(string(v.begin(), v.end()));
				if (primeNum[num] && !visited.count(num))
				{
					visited.insert(num);
					answer++;
				}
			} while (next_permutation(v.begin(), v.end()));
		} while (next_permutation(selector.begin(), selector.end()));
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//string str = "17";
	string str = "011";
	//string str = "002";
	cout << solution(str) << "\n";
	return 0;
}