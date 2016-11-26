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
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	bool flag = true;
	for(int i = 0; i < n-1; ++i)
	{
		if(a[i] < 0)
		{
			cout << "NO" << endl;
			return 0;
		}
		if(a[i] % 2 == 1)
		{
			--a[i+1];
		}
	}
	cout << (a[n-1] >= 0 && a[n-1] % 2 == 0 ? "YES" : "NO") << endl;

	return 0;
}