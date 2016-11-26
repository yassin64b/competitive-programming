#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int LEN = 1048576;

int main()
{
	int* cnt = new int[LEN];
	fill(cnt, cnt+LEN, 0);
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t)
	{
		char c;
		cin >> c;
		if(c == '+' || c == '-')
		{
			int pat = 0;
			long long tmp;
			cin >> tmp;
			int offset = 0;
			while(tmp)
			{
				int i = (tmp % 10) % 2;
				tmp /= 10;
				pat |= (i << offset);
				++offset;
			}
			//cout << pat << " ";
			cnt[pat] += (c == '+' ? 1 : -1);
			//cout << cnt[pat] << endl;
		}
		else
		{
			long long tmp;
			cin >> tmp;
			int pat = 0, offset = 0;
			while(tmp)
			{
				pat |= ((tmp%10) << offset);
				++offset;
				tmp /= 10;
			}
			cout << cnt[pat] << endl;
		}
	}
	delete[] cnt;
	return 0;
}