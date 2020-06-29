#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int L, C;
vector<char> v;
vector<int> temp;

void Proc(const int index)
{
	if (temp.size() == L)
	{
		string str;
		bool flag = false;
		int cnt = 0;
		for (const auto& index : temp)
		{
			//모음이 존재하는지 판단
			if (!flag && (v[index] == 'a' || v[index] == 'e' || v[index] == 'i' || v[index] == 'o' || v[index] == 'u'))
			{
				flag = true;
			}
			//자음이 2개 이상 존재하는지 판단
			if (cnt < 2 && v[index] != 'a' && v[index] != 'e' && v[index] != 'i' && v[index] != 'o' && v[index] && 'u')
			{
				cnt++;
			}
			str += v[index];
		}
		//조건에 충족하면 출력
		if (flag && cnt > 1)
		{
			cout << str << "\n";
		}
	}
	else
	{
		for (int i = index; i < C; i++)
		{
			temp.emplace_back(i);
			Proc(i + 1);
			temp.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> L >> C;
	v = vector<char>(C, ' ');
	for (int i = 0; i < C; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	Proc(0);
	return 0;
}