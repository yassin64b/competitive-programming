#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	int a = -1, b = -1, c = -1;
	bool flag = true;
	for(int i = 0; i < n; ++i)
	{
		cin >> v[i];
		if(a == -1)
		{
			a = v[i];
		}
		else if(a != v[i])
		{
			if(b == -1)
			{
				b = v[i];
			}
			else if(b != v[i])
			{
				if(c == -1)
				{
					c = v[i];
				}
				else if(c != v[i])
				{
					flag = false;
				}
			}
		}
	}	
	if(!flag)
	{
		cout << "NO" << endl;
	}
	else
	{
		if(c == -1) 
		{
			cout << "YES" << endl;
		}
		else if(abs(a - b) == abs(a - c) || abs(b - a) == abs(b - c) || abs(c - a) == abs(c -b))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}