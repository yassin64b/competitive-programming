#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t)
	{
		int N, cur;
		cin >> N;

		vector<int> v(2500);

		for(int i = 0; i < 2*N-1; ++i)
			for(int j = 0; j < N; ++j)
			{
				cin >> cur;
				++v[cur-1];
			}

		cout << "Case #" << t << ": ";
		for(int i = 0; i < 2500; ++i)
			if(v[i] % 2) cout << i+1 << ' ';

		cout << '\n';
	}

	return 0;
}