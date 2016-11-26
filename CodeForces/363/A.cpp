#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	char dir[200000];
	for(int i = 0; i < n; ++i)
		cin >> dir[i];

	int x[200000];
	for(int i = 0; i < n; ++i)
		cin >> x[i];

	int dist = -1;
	bool flag = true;
	for(int i = 0; flag && i < n-1; ++i)
	{
		if(dir[i] == 'R')
		{
			if(dir[i+1] == 'L')
			{
				if(dist == -1 || (x[i+1] - x[i]) / 2 < dist)
					dist = (x[i+1] - x[i]) / 2;
			}
		}
	}
	cout << dist << endl;
	return 0;
}