#include <iostream>

using namespace std;

int main()
{
	int n, c;
	cin >> n >> c;

	int cur, last = 0, cnt = 1;
	cin >> last;
	for(int i = 1; i < n; ++i)
	{
		cin >> cur;
		if(cur - last > c)
		{
			cnt = 1;
		}
		else
		{
			++cnt;
		}
		last = cur;
	}
	cout << cnt << endl;
}