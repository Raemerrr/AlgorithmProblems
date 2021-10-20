#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
long long answer;
vector<int> v;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  while (N--)
  {
    int num = 0;
    cin >> num;
    while (!v.empty() && v.back() < num)
    {
      v.pop_back();
    }
    v.push_back(num);
    answer += v.size() - 1;
  }
  cout << answer << "\n";
  return 0;
}