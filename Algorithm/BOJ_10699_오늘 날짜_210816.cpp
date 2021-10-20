#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

int main() {
	time_t t = std::time(0);   // get time now
	tm* now = std::localtime(&t);
	//³â
	cout << (now->tm_year + 1900) << '-';
	cout.width(2); cout.fill('0');
	//¿ù
	cout << (now->tm_mon + 1) << '-'
		//ÀÏ
		<< (now->tm_mday) << "\n";
	return 0;
}