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
	int N, x;
	cin >> N >> x;

	if(x == 1 || x == 2*N-1)
	{
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	if(N == 2)
	{
		cout << "1\n2\n3" << endl;
		return 0;
	}
	vector<int> res(2*N-1);

	if(x == 2)
	{
		res[(2*N-1)/2 - 1] = x+1;
		res[(2*N-1)/2] = x;
		res[(2*N-1)/2 + 1] = x-1;
		res[(2*N-1)/2 + 2] = x+2;
	}
	else
	{
		res[(2*N-1)/2 - 1] = x-1;
		res[(2*N-1)/2] = x;
		res[(2*N-1)/2 + 1] = x+1;
		res[(2*N-1)/2 + 2] = x-2;
	}
	

	int val = 1;
	for(int i = 0; i < (int)res.size(); ++i)
	{
		while(i >= (2*N-1)/2 - 1 && i <= (2*N-1)/2 + 2)
			++i;
		while(x == 2 && val >= x-1 && val <= x+2)
			++val;
		while(x != 2 && val >= x-2 && val <= x+1)
			++val;
		res[i] = val++;
	}
	for(int i = 0; i < (int)res.size(); ++i)
		cout << res[i] << endl;
	return 0;
}