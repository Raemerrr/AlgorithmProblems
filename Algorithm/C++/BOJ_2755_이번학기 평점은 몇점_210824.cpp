#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int N, sumGrades;
vector<vector<string>> v;
double grades, answer;

map<string, double> m{
{"A+",4.3 },
{"A0", 4.0},
{"A-", 3.7},
{"B+", 3.3},
{"B0", 3.0},
{"B-", 2.7},
{"C+", 2.3},
{"C0", 2.0},
{"C-", 1.7},
{"D+", 1.3},
{"D0", 1.0},
{"D-", 0.7},
{"F", 0.0}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	v.assign(N, vector<string>());
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		string str; getline(cin, str);
		vector<string> strArr;
		istringstream ss(str);
		string stringBuffer;
		while (getline(ss, stringBuffer, ' '))
		{
			strArr.emplace_back(stringBuffer);
		}
		v[i] = strArr;
	}
	for (const vector<string>& d : v)
	{
		int g = stoi(d[1]);
		grades += g * m[d[2]];
		sumGrades += g;
	}
	double temp = grades / sumGrades;
	temp += 0.000000001;
	answer = ceil(temp * 100) * 0.01;
	cout << fixed;
	cout.precision(2);
	cout << answer << "\n";
	return 0;
}

//#include <iostream>
//#include <cmath>
//#include <sstream>
//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//int N, sumGrades, grades;
//vector<vector<string>> v;
//float answer;
//
//map<string, int> m{
//{"A+",43 },
//{"A0", 40},
//{"A-", 37},
//{"B+", 33},
//{"B0", 30},
//{"B-", 27},
//{"C+", 23},
//{"C0", 20},
//{"C-", 17},
//{"D+", 13},
//{"D0", 10},
//{"D-", 07},
//{"F", 00}
//};
//
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> N;
//	v.assign(N, vector<string>());
//	cin.ignore();
//	for (int i = 0; i < N; i++)
//	{
//		string str; getline(cin, str);
//		vector<string> strArr;
//		istringstream ss(str);
//		string stringBuffer;
//		while (getline(ss, stringBuffer, ' '))
//		{
//			strArr.emplace_back(stringBuffer);
//		}
//		v[i] = strArr;
//	}
//	for (const vector<string>& d : v)
//	{
//		int g = stoi(d[1]);
//		grades += g * m[d[2]];
//		sumGrades += g;
//	}
//	float t = ((grades * 100) / sumGrades) * 0.1;
//	answer = ceil(((grades * 100) / sumGrades) * 0.1) * 0.01;
//	cout << fixed;
//	cout.precision(2);
//	cout << answer << "\n";
//	return 0;
//}