#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <utility>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	map<pair<int,int>,pair<int,pair<int,int>>> m;
	vector<int> a(n), b(n), c(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i] >> b[i] >> c[i];
		if(c[i] > m[{a[i],b[i]}].first)
		{
			m[{a[i],b[i]}].first = m[{b[i],a[i]}].first = c[i];
			m[{a[i],b[i]}].second.first = m[{b[i],a[i]}].second.first = i+1; 
			m[{a[i],b[i]}].second.second = m[{b[i],a[i]}].second.second = 0;
		} 
		else if(c[i] == m[{a[i],b[i]}].first)
		{
			m[{a[i],b[i]}].first = m[{b[i],a[i]}].first = c[i];
			if(m[{a[i],b[i]}].second.first > 0)
				m[{a[i],b[i]}].second.second = m[{b[i],a[i]}].second.second = i+1;
			else
				m[{a[i],b[i]}].second.first = m[{b[i],a[i]}].second.first = i+1; 
		}

		if(b[i] > m[{a[i],c[i]}].first)
		{
			m[{a[i],c[i]}].first = m[{c[i],a[i]}].first = b[i];
			m[{a[i],c[i]}].second.first = m[{c[i],a[i]}].second.first = i+1;
			m[{a[i],c[i]}].second.second = m[{c[i],a[i]}].second.second = 0;
		}
		else if(b[i] == m[{a[i],c[i]}].first)
		{
			m[{a[i],c[i]}].first = m[{c[i],a[i]}].first = b[i];
			if(m[{a[i],c[i]}].second.first > 0)
				m[{a[i],c[i]}].second.second = m[{c[i],a[i]}].second.second = i+1;
			else
				m[{a[i],c[i]}].second.first = m[{c[i],a[i]}].second.first = i+1;
		}

		if(a[i] > m[{b[i],c[i]}].first)
		{
			m[{b[i],c[i]}].first = m[{c[i],b[i]}].first = a[i];
			m[{b[i],c[i]}].second.first = m[{c[i],b[i]}].second.first = i+1;
			m[{b[i],c[i]}].second.second = m[{c[i],b[i]}].second.second = 0;
		}
		else if(a[i] == m[{b[i],c[i]}].first)
		{
			if(m[{b[i],c[i]}].second.first > 0)
				m[{b[i],c[i]}].second.second = m[{c[i],b[i]}].second.second = i+1;
			else
				m[{b[i],c[i]}].second.first = m[{c[i],b[i]}].second.first = i+1;
		}

	}
	double res = 0; int res1 = -1, res2 = -1;
	for(int i = 0; i < n; ++i)
	{
		int tmp = min(a[i], min(b[i], c[i]));
		if(tmp / 2. > res)
		{
			res = tmp / 2.;
			res1 = i+1, res2 = -1;
		}
		if(tmp == c[i])
		{
			double x = max(res, min(a[i]/2., min(b[i]/2., c[i]/2.+m[{a[i],b[i]}].first/2.)));
			if(x > res)
			{
				if(m[{a[i],b[i]}].second.first != i+1)
				{
					res = x;
					res1 = i+1, res2 = m[{a[i],b[i]}].second.first;
				} 
				else if(m[{a[i],b[i]}].second.second != 0)
				{
					res = x;
					res1 = i+1, res2 = m[{a[i],b[i]}].second.second;
				}
			
			}
		}
		if(tmp == b[i])
		{
			double x = max(res, min(a[i]/2., min(c[i]/2., b[i]/2.+m[{a[i],c[i]}].first/2.)));
			if(x > res)
			{
				if(m[{a[i],c[i]}].second.first != i+1)
				{
					res = x;
					res1 = i+1, res2 = m[{a[i],c[i]}].second.first;
				} 
				else if(m[{a[i],c[i]}].second.second != 0)
				{
					res = x;
					res1 = i+1, res2 = m[{a[i],c[i]}].second.second;
				}
			}
		}
		if(tmp == a[i])
		{
			double x = max(res, min(a[i]/2.+m[{b[i],c[i]}].first/2., min(c[i]/2., b[i]/2.)));
			if(x > res)
			{
				if(m[{b[i],c[i]}].second.first != i+1)
				{
					res = x;
					res1 = i+1, res2 = m[{b[i],c[i]}].second.first;
				} 
				else if(m[{b[i],c[i]}].second.second != 0)
				{
					res = x;
					res1 = i+1, res2 = m[{b[i],c[i]}].second.second;
				}
			}
		}
	}
	if(res2 == -1)
		cout << 1 << endl << res1 << endl;
	else
	{
		cout << 2 << endl;
		if(res1 < res2)
			cout << res1 << " " << res2 << endl;
		else
			cout << res2 << " " << res1 << endl;
	}
	return 0;
}