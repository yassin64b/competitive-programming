#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n, d;
	cin >> n >> d;

	vector<string> v(d);
	for(int i = 0; i < d; ++i)
	{
		cin >> v[i];
	}
	
	int maxdays = 0, cur = 0;
	for(int i = 0; i < d; ++i)
	{
		bool beat = false;
		for(int j = 0; !beat && j < n; ++j)
		{
			if(v[i][j] == '0')
				beat = true;
		}

		if(beat)
		{
			++cur;
			maxdays = (cur > maxdays ? cur : maxdays);
		}
		else
		{
			cur = 0;
		}
	}
	cout << maxdays << endl;
}