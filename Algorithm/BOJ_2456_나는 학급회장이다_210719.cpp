#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rank
{
	int id;
	int _3;
	int _2;
	int _1;
	int sum;
	Rank(int id, int _3, int _2, int _1, int sum) : id(id), _3(_3), _2(_2), _1(_1), sum(sum) {}
	void setCnt(const int num) {
		switch (num)
		{
		case 1:
			_1++;
			break;
		case 2:
			_2++;
			break;
		case 3:
			_3++;
			break;
		default:
			break;
		}
		sum += num;
	}

	//다른 Rank객체와 비교
	bool operator==(const Rank& rhs) const
	{
		return sum == rhs.sum && _3 == rhs._3 && _2 == rhs._2 && _1 == rhs._1;
	}
};

int N;
vector<Rank> v;

//코드가.. 난해해져서.. 따로 함수에 담아놨다..
void Sort() {
	sort(v.begin(), v.end(), [](const Rank& a, const Rank& b) {
		if (a.sum == b.sum)
		{
			if (a._3 == b._3)
			{
				if (a._2 == b._2)
				{
					return a._1 > b._1;
				}
				return a._2 > b._2;
			}
			return a._3 > b._3;
		}
		return a.sum > b.sum;
		});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	v.emplace_back(1, 0, 0, 0, 0);
	v.emplace_back(2, 0, 0, 0, 0);
	v.emplace_back(3, 0, 0, 0, 0);
	cin >> N;
	while (N--)
	{
		int A = 0, B = 0, C = 0;
		cin >> A >> B >> C;
		v[0].setCnt(A);
		v[1].setCnt(B);
		v[2].setCnt(C);
	}
	Sort();
	if (v[0] == v[1]) cout << 0 << " " << v[0].sum << "\n";
	else cout << v[0].id << " " << v[0].sum << "\n";
	return 0;
}