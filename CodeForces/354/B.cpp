#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int N, T;
	cin >> N >> T;
	
	vector<vector<int>> v(N, vector<int>(N, 0)); 
	int res = 0;
	v[0][0] = 1024 * T;

	for(int i = 0; i < N-1; ++i)
	{
		for(int j = 0; j < i+1; ++j)
		{
			//cout << v[i][j] << ' ';
			if(v[i][j] >= 1024)
			{
				++res;
				v[i+1][j] += (v[i][j] - 1024) / 2;
				v[i+1][j+1] += (v[i][j] - 1024) / 2;
			}
		}
		//cout << endl;
	}
	for(int j = 0; j < N; ++j)
		if(v[N-1][j] >= 1024)
			++res;

	cout << res << endl;

	return 0;
}