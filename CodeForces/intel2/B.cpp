#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m));
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
		}
	}

	for(int i = 0; i < m; ++i)
	{
		for(int j = i; j < m; ++j)
		{
			//swap column i and j
			vector<vector<int>> vv(v);
			for(int k = 0; k < n; ++k)
			{
				vv[k][i] = v[k][j];
				vv[k][j] = v[k][i];
			}
			bool flag = true;
			
			
			//check each row for max 1 swap
			for(int a = 0; flag && a < n; ++a)
			{
				int cnt = 0;
				for(int b = 0; b < m; ++b)
				{
					if(vv[a][b] != b+1)
						++cnt;
				}
				//cout << a << " " << cnt << endl;
				if(cnt > 2)
					flag = false;
			}
			//cout << endl;
			if(flag)
			{
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}

/*
for(int a = 0; a < n; ++a)
			{
				for(int b = 0; b < m; ++b)
					cout << vv[a][b];
				cout << endl;
			}	
			cout << endl;
			*/