#include <iostream>
#include <string>

using namespace std;

int speedCheck(const int limit, const int speed) {
	int gap = speed - limit;
	if (30 < gap)
		return 500;
	else if (20 < gap && gap < 31)
		return 270;
	else if (0 < gap && gap < 21)
		return 100;
	else
		return 0;
}

int main() {
	int limit = 0, speed = 0; cin >> limit >> speed;
	int answer = speedCheck(limit, speed);
	cout << ((answer < 1) ? "Congratulations, you are within the speed limit!\n" :
		("You are speeding and your fine is $" + to_string(answer) + ".\n"));
	return 0;
}