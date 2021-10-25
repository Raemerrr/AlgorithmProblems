#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> v, answer(prices.size());
	for (int i = 0; i < prices.size(); i++) {
		// ������ ��(prices[v.back()])�� ���� ��(prices[i])���� ũ�ٸ�
		// --> ������ ��������
		while (!v.empty() && prices[v.back()] > prices[i]) {
			// v.back()�� i���� �Ÿ� ���̸� ������ ������ �������� �Ǵ�
			answer[v.back()] = i - v.back();
			v.pop_back();
		}
		//���� �ε����� v�� �ֱ�
		v.push_back(i);
	}
	// ������ ���� ó������ �ʰ� ������ ������ ���� ó��
	while (!v.empty()) {
		// ���� ū �ε���(prices.size() - 1)�� ����� �ε���(v.back())���� �Ÿ� ����
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