#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

enum language { cpp, java, python, langAll }; int languageSize = 3;
enum tech { backend, frontend, techAll }; int techSize = 2;
enum food { chicken, pizza, foodAll }; int foodSize = 2;
enum career { junior, senior, careerAll }; int careerSize = 2;

//Data 저장 변수 초기화
vector<vector<vector<vector<vector<int>>>>> v(languageSize,
	vector<vector<vector<vector<int>>>>(techSize,
		vector<vector<vector<int>>>(careerSize,
			vector<vector<int>>(foodSize,
				vector<int>())
			)
		));

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	// ' ' 기준으로 문자열 분리
	for (auto& d : info)
	{
		vector<string> strArr;
		istringstream ss(d);
		string stringBuffer;
		while (getline(ss, stringBuffer, ' '))
		{
			strArr.emplace_back(stringBuffer);
		}
		int languageFlag = (strArr[0] == "cpp") ? cpp : ((strArr[0] == "java") ? java : python);
		int techFlag = (strArr[1] == "backend") ? backend : frontend;
		int carrerFlag = (strArr[2] == "junior") ? junior : senior;
		int foodFlag = (strArr[3] == "chicken") ? chicken : pizza;
		v[languageFlag][techFlag][carrerFlag][foodFlag].push_back(stoi(strArr[4]));
	}

	// 문자열 분리 후 점수를 오름차순 정렬
	for (int a = 0; a < languageSize; a++)
	{
		for (int b = 0; b < techSize; b++)
		{
			for (int c = 0; c < careerSize; c++)
			{
				for (int d = 0; d < foodSize; d++)
				{
					sort(v[a][b][c][d].begin(), v[a][b][c][d].end());
				}
			}
		}
	}

	for (auto& d : query)
	{
		int cnt = 0;
		vector<string> strArr;
		istringstream ss(d);
		string stringBuffer;
		// ' ' 기준으로 문자열 분리 후 and를 건너 뛴 인덱스 번호이다.
		while (getline(ss, stringBuffer, ' '))
		{
			strArr.emplace_back(stringBuffer);
		}
		int languageFlag = (strArr[0] == "cpp") ? cpp : ((strArr[0] == "java") ? java : ((strArr[0] == "python") ? python : langAll));
		int techFlag = (strArr[2] == "backend") ? backend : ((strArr[2] == "frontend") ? frontend : techAll);
		int careerFlag = (strArr[4] == "junior") ? junior : ((strArr[4] == "senior") ? senior : careerAll);
		int foodFlag = (strArr[6] == "chicken") ? chicken : (strArr[6] == "pizza") ? pizza : foodAll;
		int score = stoi(strArr[7]);
		// lower_bound를 이용해 기준 점수 이상의 사람의 수를 빠르게 파악한다. 
		for (int a = (languageFlag == langAll ? 0 : languageFlag); a < (languageFlag == langAll ? languageSize : languageFlag + 1); a++)
		{
			for (int b = (techFlag == techAll ? 0 : techFlag); b < (techFlag == techAll ? techSize : techFlag + 1); b++)
			{
				for (int c = (careerFlag == careerAll ? 0 : careerFlag); c < (careerFlag == careerAll ? careerSize : careerFlag + 1); c++)
				{
					for (int d = (foodFlag == foodAll ? 0 : foodFlag); d < (foodFlag == foodAll ? foodSize : foodFlag + 1); d++)
					{
						cnt += v[a][b][c][d].size() - (lower_bound(v[a][b][c][d].begin(), v[a][b][c][d].end(), score) - v[a][b][c][d].begin());
					}
				}
			}
		}
		answer.push_back(cnt);
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<string> info{ "java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50" };
	vector<string> query{ "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
	for (const auto d : solution(info, query)) { cout << d << " "; }cout << "\n";
	return 0;
}

