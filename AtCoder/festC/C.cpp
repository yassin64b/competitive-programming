#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

const long long mod = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	vector<int> T(N), A(N);
	
	for(int i = 0; i < N; ++i) 
		cin >> T[i];
	for(int i = 0; i < N; ++i)
		cin >> A[i];

	if(N == 1)
	{
		if(T[0] != A[0])
			cout << 0 << endl;
		else
			cout << 1 << endl;
		return 0;
	}
	vector<pair<int, bool>> real1(N, {0, false}), real2(N, {0, false});

	real1[0] = {T[0], true};
	real2[N-1] = {A[N-1], true};

	for(int i = 1; i < N; ++i)
	{
		if(T[i] > T[i-1])
		{
			real1[i] = {T[i], true};
		}
		else
		{
			real1[i] = {T[i], false};
		}
		if(A[N-i-1] > A[N-i])
		{
			real2[N-i-1] = {A[N-i-1], true};
		}
		else
		{
			real2[N-i-1] = {A[N-i-1], false};
		}
	}
	long long res = 1;
	for(int i = 0; i < N; ++i)
	{
		//cout << real1[i].first << (real1[i].second ? "T" : "F") << '\t' << real2[i].first << (real2[i].second ? "T" : "F") << endl;
		if(real1[i].second == true)
		{
			if(real2[i].second == true)
			{
				if(real1[i].first != real2[i].first)
				{
					//cout << "first" << endl;
					cout << 0 << endl;
					return 0;
				}
			}
			else
			{
				if(real2[i].first < real1[i].first)
				{
					//cout << "second" << endl;
					cout << 0 << endl;
					return 0;
				}
			}
		}
		else if(real2[i].second == true)
		{
			if(real1[i].first < real2[i].first)
			{
				//cout << "third" << endl;
				cout << 0 << endl;
				return 0;
			}
		}
		else
		{
			long long val = min(real1[i].first, real2[i].first);
			res = (res * val) % mod;
		}
	}
	cout << res << endl;
	return 0;
}