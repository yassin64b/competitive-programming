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

	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	vector<int> b(m+1, 0);
	queue<int> place;
	int free = 0;
	for(int i = 0; i < n; ++i)
	{
		if(a[i] <= m)
			++b[a[i]];
		else
			++free, place.push(i);
	}	
	
	int opt = n / m, changed = 0;

	for(int i = 1; i <= m; ++i)
	{
		int j = 0;
		while(b[i] > opt)
		{
			--b[i];
			for(; j < n; ++j)
			{
				if(a[j] == i)
				{
				 	place.push(j);
				 	++j;
				 	break;
				}
			}
		}
	}
	
	int i = 1;
	while(!place.empty())
	{
		while(i <= m && b[i] >= opt)
			++i;
		if(i > m) break;
		++b[i], ++changed;
		a[place.front()] = i;
		place.pop();		
	}

	cout << opt << " " << changed << endl;
	for(int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}

/*
50 10
820558149 7 10 7 9 9 7 7 7 9 7 10 8 8 10 8 6 8 9 9 8 971788012 9 8 9 10 6 5 871178015 4 10 5 7 9 10 9 10 4 643998638 8 10 9 10 766953454 5 9 10 10 8 10

*/