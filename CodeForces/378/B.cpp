#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, L = 0, R = 0;
	cin >> n;
	vector<int> l(n), r(n), diff(n);
	for(int i = 0; i < n; ++i)
		cin >> l[i] >> r[i], L += l[i], R += r[i], diff[i] = l[i]-r[i];

	int res = abs(L-R), k = 0;
	
	int ind1 = 0, ind2 = 0;
	for(int i = 1; i < n; ++i)
	{
		if(diff[i] < diff[ind1])
		{
			ind1 = i;
		}
		if(diff[i] > diff[ind2])
		{
			ind2 = i;
		}
	}

	if(abs(L-l[ind1]+r[ind1]-(R-r[ind1]+l[ind1])) > res)
		k = ind1+1, res = abs(L-l[ind1]+r[ind1]-(R-r[ind1]+l[ind1]));
	if(abs(L-l[ind2]+r[ind2]-(R-r[ind2]+l[ind2])) > res)
		k = ind2+1, res = abs(L-l[ind2]+r[ind2]-(R-r[ind2]+l[ind2]));
	cout << k << endl;
	return 0;
}