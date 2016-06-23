#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N;
	long long cur = 0;
	cin >> N >> cur;

	
	int distressed = 0;
	for(int i = 0; i < N; ++i)
	{
		char c; 
		int d;
		cin >> c >> d;

		if(c == '+')
			cur += d;
		else if(c == '-') 
		{
			if(d > cur)
				++distressed;
			else
				cur -= d;
		}
		
	}

	cout << cur << ' ' << distressed << endl;
}