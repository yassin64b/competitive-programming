#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
	int N, H, K;
	cin >> N >> H >> K;

	vector<int> a(N);
	for(int i = 0; i < N; ++i)
		cin >> a[i];
	
	long long res = 0; 
	int cur = 0;
	//int i = 0;
	
	for(int i = 0; i < N || cur > 0; )
	{
		//cout << i << endl;
		while(i < N && cur + a[i] <= H)
		{
			//cout << i << endl;
			cur += a[i];
			++i;
		}

		if(cur >= K)
		{
			res += cur / K;
			cur = cur % K;
		}
		else
		{
			++res;
			cur = 0;
		}

		//cout << i << "," << cur << " - " << res << endl;

	}

	cout << res << endl;
}