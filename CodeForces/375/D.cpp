#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <utility>
using namespace std;

const char LAND = '*';
const char WAT = '.';


int main()
{
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;

	vector<string> map(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> map[i];
	}

	vector<set<pair<int,int>>> lakes;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(map[i][j] == WAT)
			{
				bool flag = false;
				for(int a = 0; !flag && a < (int)lakes.size(); ++a)
				{
					for(const pair<int,int> p: lakes[a])
					{
						if(abs(p.first-i)+abs(p.second-j) == 1)
						{
							flag = true;
							lakes[a].insert({i,j});
							break;
						}
					}
				}
				if(!flag)
					lakes.push_back({{i,j}});
			}
		}
	}
	for(int a = 0; a < (int)lakes.size(); ++a)
	{
		for(const pair<int,int> p: lakes[a])
		{
			bool flag = false;
			for(int b = 0; b < (int)lakes.size(); ++b)
			{
				if(a == b)
					continue;
				for(const pair<int,int> q: lakes[b])
				{
					if(abs(p.first-q.first)+abs(p.second-q.second) == 1)
					{
						flag = true;
						break;
					}
				}
				if(flag)
				{
					for(const pair<int,int> q: lakes[b])
					{
						lakes[a].insert(q);
					}
					lakes[b] = {};
					break;
				}
			}
			if(flag)
			{
				--a;
				break;
			}	
		}
	}

	vector<set<pair<int,int>>> rlakes;
	for(int a = 0; a < (int)lakes.size(); ++a)
	{
		bool flag = false;
		for(const pair<int,int> p: lakes[a])
		{
			if(p.first == 0 || p.first == n-1 || p.second == 0 || p.second == m-1)
			{
				flag = true;
				break;
			}
		}
		if(!flag && !lakes[a].empty())
			rlakes.push_back(lakes[a]);
	}
	
	sort(rlakes.begin(), rlakes.end(), 
	    [](const set<pair<int,int>>& lhs, const set<pair<int,int>>& rhs) -> bool
		{ 
		    return (lhs.size() < rhs.size()); 
		});

	int del = ((int)rlakes.size()) - k;
	int a = 0, cnt = 0;
	for(int i = 0; i < del; ++i)
	{
		for(const pair<int,int> p: rlakes[a])
		{
			map[p.first][p.second] = LAND;
			++cnt;
		}
		++a;
	}

	cout << cnt << endl;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	return 0;
}