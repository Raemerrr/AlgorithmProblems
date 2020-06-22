//�ٽ� stack�� ����ٸ� �����͸� �װ� �� ���� ������ �����Ϳ� ���ٸ� pop_back �ٸ��ٸ� �ױ�
//�������� stack�� ������� �ʴٸ�, �� �ܾ�� �߸��� �ܾ�
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N, ans;
vector<string> v;

void Func()
{
	//�Է� ���� string�� ���� ������ Ž���Ѵ�.
	for (auto& data : v)
	{
		//stack ������ �̿��� �ذ��Ѵ�.
		vector<char> stack;
		while (!data.empty())
		{
			char front = data[0];
			if (stack.empty())
			{
				stack.emplace_back(front);
			}
			else
			{
				if (stack[stack.size() - 1] == front)
				{
					//���߿� ���� �����͸� ���� ���� �������� ���� stack���
					stack.pop_back();
				}
				else
				{
					stack.emplace_back(front);
				}
			}
			//erase�� begin()���� �ϱ⶧���� ���ɻ�.. ū ������ ����..?
			data.erase(data.begin());
		}
		if (stack.empty())
		{
			ans++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v = vector<string>(N, "");
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	Func();
	cout << ans << "\n";
	return 0;
}