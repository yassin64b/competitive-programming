#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n;
int x = 0;
int eat(vector<int> &a, int j)
{
	if(j > 0 && j-1 >= x && a[j-1] < a[j])
	{
		a[j-1] += a[j];
		for(int i = j; i < n-1; ++i)
			a[i] = a[i+1];
		a[n-1] = -1;
		return -1;
	}
	//cout << j << endl;
	if(j < n-1 && a[j+1] < a[j])
	{
		a[j] += a[j+1];
		for(int i = j+1; i < n-1; ++i)
			a[i] = a[i+1];
		a[n-1] = -1;
		return 1;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	
	int k;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	cin >> k;
	vector<int> b(k);
	for(int i = 0; i < k; ++i)
		cin >> b[i];

	vector<string> res;
	
	for(int i = 0; i < k; ++i)
	{
		while(x < k && b[x] == a[x])
			++x;
		if(x == k)
			break;
		/*cout << x << endl;
		for(int i = 0; i < n; ++i)
			cout << a[i] << " ";
		cout << endl << endl;*/
		int sum = 0, j;
		for(j = x; sum < b[x] && j < n; ++j)
		{
			sum += a[j];
		}
		if(sum != b[x])
		{
			cout << "NO" << endl;
			return 0;
		}
		bool flag = false;
		int maxval = a[x], ind = x;
		for(int y = x+1; y < j; ++y)
		{
			if(a[y] != a[y-1]) flag = true;
			if(a[y] > maxval)
			{
				maxval = a[y];
				ind = y;
			}
		}
		if(!flag)
		{
			cout << "NO" << endl;
			return 0;
		}
		for(int y = 0; y < j-x-1; ++y)
		{
			int tmp;
			for(int z = x; z < j; ++z)
			{
				if(a[z] >= maxval && (tmp = eat(a, z)))
				{
					res.push_back(to_string(z+1) + " " + (tmp == -1 ? "L" : "R"));
					ind += (tmp == -1 ? -1 : 0);
					break;
				}
			}
		}

		/*for(int j = x; j < n; ++j)
		{
			int tmp;
			if((tmp = eat(a, j)))
			{
				res.push_back(to_string(j+1) + " " + (tmp == -1 ? "L" : "R"));
				break;
			}
		}*/
	}
	/*for(int i = 0; i < n; ++i)
			cout << a[i] << " ";
		cout << endl << endl;*/
	if((int)res.size() != n - k)
	{
		cout << "NO" << endl;
		return 0;
	}
	else
	{
		for(int i = 0; i < k; ++i)
		{
			if(a[i] != b[i])
			{
				cout << "NO" << endl;
				return 0;
			}
		}
		cout << "YES" << endl;
		for(int i = 0; i < (int)res.size(); ++i)
			cout << res[i] << endl;
		cout << endl;
	}

	return 0;
}