#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v(5);
	for(int i = 0; i < 5; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());
	int max = 0;
	for(int i = 0; i < 5; ++i)
	{
		int cur = v[i], j = i, cnt = 1;

		while(j < 5 && v[j] == v[j+1] && cnt < 3)
		{
			++j, ++cnt;
			cur += v[j];
		}
		if(cur > max && cnt >= 2)
			max = cur;
	}

	int res = 0;
	for(int i = 0; i < 5; ++i)
		res += v[i];

	cout << res - max << endl;
}
