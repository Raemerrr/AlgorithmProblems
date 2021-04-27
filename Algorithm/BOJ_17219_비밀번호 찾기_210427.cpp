#include <iostream>
#include <map>
#include <string>

using namespace std;

int N, M;
map<string, string> m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	while (N--)
	{
		string k, v; cin >> k >> v;
		m[k] = v;
	}
	while (M--)
	{
		string site; cin >> site;
		//���� ���� ������.. ������ �ڵ带 ����..
		cout << ((m.count(site)) ? m[site] : "empty") << "\n";
	}
	return 0;
}