#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	while (true)
	{
		int num1 = 0, num2 = 0; std::cin >> num1 >> num2;
		if (num1 == 0 && num2 == 0) break;
		std::cout << ((num2 < num1) ? "Yes" : "No") << "\n";
	}
	return 0;
}