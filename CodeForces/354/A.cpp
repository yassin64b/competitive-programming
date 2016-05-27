#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int N, pos1, posn;
	cin >> N;

	for(int i = 0; i < N; ++i)
	{
		int a;
		cin >> a;

		if(a == 1)
			pos1 = i;
		if(a == N)
			posn = i;
	}

	int res;
	if(pos1 < posn)
		res = max(0+posn, N-pos1-1);
	else
		res = max(0+pos1, N-posn-1);

	cout << res << endl;
}