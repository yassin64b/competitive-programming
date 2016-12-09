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

vector<int> p, rk;

int findSet(int i) { return (p[i] == i ? i : (p[i] = findSet(p[i]))); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) 
{
	int x = findSet(i), y = findSet(j);
	if(rk[x] > rk[y])
		p[y] = x;
	else if(rk[x] < rk[y])
		p[x] = y;
	else
		p[x] = y, rk[y]++;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
   
	vector<int> colors(n);
	for(int i = 0; i < n; ++i)
		cin >> colors[i];
	vector<pair<int,int>> socks(m);
	for(int i = 0; i < m; ++i)
		cin >> socks[i].first >> socks[i].second, --socks[i].first, --socks[i].second;

	p.assign(n, 0); rk.assign(n, 0);
	for(int i = 0; i < n; ++i) p[i] = i;
	for(int i = 0; i < m; ++i)
	{
		if(!isSameSet(socks[i].first, socks[i].second))
		{
			unionSet(socks[i].first, socks[i].second);
		}
	}

	vector<vector<int>> colorcnt(n);
	for(int i = 0; i < n; ++i)
	{
	   colorcnt.at(findSet(i)).push_back(colors[i]);			
	}

	int cnt = 0;
	for(int i = 0; i < n; ++i)
	{
        if (colorcnt[i].size() <= 1) continue;
        
        sort(colorcnt[i].begin(), colorcnt[i].end());

		int stay = 0, longest = 1, cur = 1;
		for(size_t j = 1; j < colorcnt[i].size(); ++j)
		{
			if(colorcnt[i].at(j-1) == colorcnt[i].at(j)) {
                ++cur;
                if (cur > longest) {
                    stay = j;
                    longest = cur;
                }  
            } else {
                cur = 1;
            }
		}

		for(size_t j = 0; j < colorcnt[i].size(); ++j)
		{
			if(colorcnt[i].at(j) != colorcnt[i].at(stay)) cnt += 1;
		}
	}

	cout << cnt << endl;
	return 0;
}