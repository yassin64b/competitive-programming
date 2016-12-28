#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
#include <utility>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string s, t;
	int N;
	cin >> N >> s >> t;

	for(int i = 0; i < N; ++i)
	{
		bool flag = true;
		for(int j = 0; flag && j < N; ++j)
		{
			if(i+j < N && s[i+j] != t[j])
				flag = false;
		}
		if(flag)
		{
			cout << i + N << endl;
			return 0;
		}
	}
	cout << 2*N << endl;
	return 0;
}