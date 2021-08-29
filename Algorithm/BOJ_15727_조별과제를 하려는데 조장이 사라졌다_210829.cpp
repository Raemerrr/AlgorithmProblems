#include <iostream>

int main() {
	int num = 0; std::cin >> num;
	if (num % 5 == 0) std::cout << (num / 5);
	else std::cout << ((num / 5) + 1);
	return 0;
}