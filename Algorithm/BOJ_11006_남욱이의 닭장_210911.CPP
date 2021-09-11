#include <iostream>

using namespace std;

int N;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  while (N--)
  {
    int num1 = 0, num2 = 0;
    cin >> num1 >> num2;
    int answer1 = (num2 * 2) - num1;
    int answer2 = num2 - answer1;
    cout << answer1 << " " << answer2 << "\n";
  }
  return 0;
}