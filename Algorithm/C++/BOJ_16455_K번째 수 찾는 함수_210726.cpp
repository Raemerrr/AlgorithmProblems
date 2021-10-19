#include <iostream>
#include <vector>
#include <algorithm>

int kth(std::vector<int> &a, int k) {
	nth_element(a.begin(), a.begin() + k - 1, a.end());
	return a[k - 1];
}

//���� ���� �� main()�Լ� ���ʿ�
int main() {
	std::vector<int> arr = { 38,27,43,3,9,82,10 };
	std::cout << kth(arr, 2) << "\n";
}