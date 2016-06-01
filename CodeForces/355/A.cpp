#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
	int N, H;
	cin >> N >> H;

	int res = 0;
	for(int i = 0; i < N; ++i)
	{
		int a;
		cin >> a;

		if(a > H)
			++res;
		++res;
	}
	cout << res << endl;
}