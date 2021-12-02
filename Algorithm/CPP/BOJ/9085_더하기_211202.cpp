#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_case = 0; cin >> test_case;
    while (test_case--)
    {
        int cnt = 0, answer = 0; cin >> cnt;
        for (int i = 0; i < cnt; i++)
        {
            int num = 0; cin >> num;
            answer += num;
        }
        cout << answer << "\n";
    }
    return 0;
}