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
	set<int> visited;
	int answer = 0;
	string tempMax = numbers;
	sort(tempMax.rbegin(), tempMax.rend());
	sort(numbers.begin(), numbers.end());
	int arrSize = stoi(tempMax);
	primeNumberSieve(arrSize);

	for (int length = 1; length <= numbers.size(); length++)
	{
		vector<int> lengthArr;
		for (int i = 0; i < length; i++) lengthArr.push_back(1);
		for (int i = 0; i < numbers.size() - length; i++) lengthArr.push_back(0);
		sort(lengthArr.begin(), lengthArr.end());
		do {
			vector<char> v;
			for (int i = 0; i < lengthArr.size(); i++)
			{
				if (lengthArr[i] == 1) {
					v.push_back(numbers[i]);
				}
			}
			do {
				int num = stoi(string(v.begin(), v.end()));
				if (primeNum[num] && !visited.count(num))
				{
					visited.insert(num);
					answer++;
				}
			} while (next_permutation(v.begin(), v.end()));
		} while (next_permutation(lengthArr.begin(), lengthArr.end()));
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