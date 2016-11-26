#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <utility>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	int k, r;
	cin >> k >> r;

	int cnt = 10;
	for(int i = 0; i <= k*10; ++i)
	{
		//cout << cnt << endl;
		if((i*10 + r) % k == 0) cnt = min((i*10 + r) / k, cnt);
		if(i > 0 && (i*10) % k == 0) cnt = min((i*10) / k, cnt);
		//cout << i*10 << "+" << r << endl;
	}
	cout << cnt << endl;

	return 0;
}