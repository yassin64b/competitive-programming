#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int N, K;
	string S;
	cin >> N >> K >> S;

	int first = 0, end = 0, cnt = 0, res = 0, tmp = 0;

	while(true)
	{
		while((cnt < K || S[end] == 'a'))
		{
			if(S[end] == 'b')
				++cnt;
			++tmp, ++end;
			if(tmp > res)
				res = tmp;
			if(end == N)
				break;
		}
		if(end == N)
			break;

		if(S[first] == 'b')
			--cnt;
		++first, --tmp;

	}

	first = 0, end = 0, cnt = 0, tmp = 0;
	while(true)
	{
		while((cnt < K || S[end] == 'b'))
		{
			if(S[end] == 'a')
				++cnt;
			++tmp, ++end;
			if(tmp > res)
				res = tmp;
			if(end == N)
				break;
		}
		if(end == N)
			break;

		if(S[first] == 'a')
			--cnt;
		++first, --tmp;

	}

	cout << res << endl;

	return 0;
}