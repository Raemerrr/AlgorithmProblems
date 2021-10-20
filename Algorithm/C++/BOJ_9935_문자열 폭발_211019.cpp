#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str, pattern, answer;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> str >> pattern;
  for (const char c : str)
  {
    answer.push_back(c);
    if (answer.size() >= pattern.size() && string(answer.end() - pattern.size(), answer.end()) == pattern)
    {
      for (int i = 0; i < pattern.size(); i++)
      {
        answer.pop_back();
      }
    }
  }
  cout << ((answer.empty()) ? "FRULA" : answer) << "\n";
  return 0;
}