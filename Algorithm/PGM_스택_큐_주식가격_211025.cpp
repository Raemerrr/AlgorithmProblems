#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> v, answer(prices.size());
	for (int i = 0; i < prices.size(); i++) {
		// 마지막 값(prices[v.back()])이 현재 값(prices[i])보다 크다면
		// --> 가격이 떨어졌다
		while (!v.empty() && prices[v.back()] > prices[i]) {
			// v.back()과 i와의 거리 차이를 가격이 유지된 구간으로 판단
			answer[v.back()] = i - v.back();
			v.pop_back();
		}
		//현재 인덱스를 v에 넣기
		v.push_back(i);
	}
	// 구간을 돌며 처리되지 않고 가격이 유지된 값들 처리
	while (!v.empty()) {
		// 가장 큰 인덱스(prices.size() - 1)와 저장된 인덱스(v.back())간의 거리 차이
		answer[v.back()] = (prices.size() - 1) - v.back();
		v.pop_back();
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> prices{ 1, 2, 3, 2, 3 };
	for (const int d : solution(prices)) {
		cout << d << " ";
	}
	cout << "\n";
	return 0;
}