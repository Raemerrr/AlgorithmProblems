//((())())
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//�ùٸ�(������ ���� ����)
bool corr;
string u, v;

int checkStr(string str) 
{
	int len = str.size();
	int check = 0;
	int pos = 0;
	corr = true;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			check++;
		}
		else
		{
			check--;
			//'����'���� ���� �ݾҴٸ�
			if (check < 0)
			{
				corr = false;
			}
		}

		if (check == 0)
		{
			pos = i;
			break;
		}
	}
	return len;
}

string test(string str)
{
	string temp = str;
	if (temp.size() > 0)
	{
		int flag = 0;
		int pos = 0;
		bool wrong = false;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(')
			{
				flag++;
			}
			else
			{
				flag--;
				if (flag < 0)
				{
					wrong = true;
				}
			}
			//���� �°� ���� ��ġ
			if (flag == 0)
			{
				pos = i;
				break;
			}
		}
		//�����ִ°ų�
		if (wrong)
		{

		}
		//�ùٸ��ų�
		else
		{

		}
	}
	return temp;
}

string solution(string p)
{
	string answer = "";
	//true : �������� ��ȣ
	//false : �ùٸ� ��ȣ
	while (true)
	{
		test(p);
	}
	return answer;
}

//string solution(string p) {
//	string answer = "";
//		//ó�� ����
//		bool flag = false;
//		string v = p;
//		string u = "";
//		while (true)
//		{
//			cout << "v : " << v << "\n";
//			cout << "u : " << u << "\n";
//			if (v.size() == 0)
//			{
//				break;
//			}
//			int check = checkStr(v);
//
//			if (check != v.size() - 1)
//			{
//				u += v.substr(0, check + 1);
//				v = v.substr(check + 1);
//			}
//			else
//			{
//				if (v.size() > 0 )
//				{
//					answer = v;
//				}
//				else
//				{
//					answer = u;
//				}
//				break;
//			}
//		}
//	return answer;
//}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;
	cout << solution(str) << "\n";
	//string str = "abcd";
	//cout << str.substr(4) << "\n";
	return 0;
}