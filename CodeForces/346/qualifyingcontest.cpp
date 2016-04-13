#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, string>>> v(M+1);

	string name;
	int rno, pnt;
	for(int i = 0; i < N; ++i)
	{
		cin >> name >> rno >> pnt;
		v[rno].push_back(make_pair(pnt, name));
	}

	for(int i = 1; i <= M; ++i)
		sort(v[i].begin(), v[i].end(), greater<pair<int,string>>());
	
	for(int i = 1; i <= M; ++i)
	{
		if(v[i].size() > 2 && v[i][1].first == v[i][2].first)
			cout << "?" << endl;
		else
			cout << v[i][0].second << " " << v[i][1].second << endl;
	}

	return 0;
}