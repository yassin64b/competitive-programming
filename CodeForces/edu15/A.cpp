#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int cnt = 0, maxcnt = 0;
	int last = 0, cur;
	for(int i = 0; i < N; ++i) {
		cin >> cur;
		if(cur > last) 
		{
			++cnt;
			if(cnt > maxcnt)
				maxcnt = cnt;
		} 
		else 
		{
			cnt = 1;
		}
		last = cur;
	}
	cout << maxcnt << endl;
}