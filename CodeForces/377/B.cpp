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


int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	int res = 0;
	for(int i = 0; i < n-1; ++i)
	{
		if(a[i] + a[i+1] < k)
		{
			res += k - (a[i] + a[i+1]);
			a[i+1] += k - (a[i] + a[i+1]);
		}
	}

	cout << res << endl;
	for(int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}