#include <iostream>

using namespace std;

int main()
{
	char f[1000][1000];
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> f[i][j];	

	int r[1000], c[1000], cnt = 0;
	for(int i = 0; i < n; ++i)
	{
		r[i] = 0;
		for(int j = 0; j < m; ++j)
			r[i] += (f[i][j] == '*');
		cnt += r[i];
	}
	for(int j = 0; j < m; ++j)
	{
		c[j] = 0;
		for(int i = 0; i < n; ++i)
			c[j] += (f[i][j] == '*');
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(cnt == r[i] + c[j] - (f[i][j] == '*'))
			{
				cout << "YES" << endl << i+1 << " " << j+1 << endl;
				return 0;
			}
		}
	}

	cout << "NO" << endl;
	return 0;

}