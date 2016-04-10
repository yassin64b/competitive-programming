#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;

//works only for small input
long long div(long long val)
{
	for(long long i = 2; i*i <= val; ++i)
	{
		if(val % i == 0)
			return i;
	}
	return 0;
}

int main()
{
	int T, N, J, count;
	long long val, d;
	bool flag, first;
	vector<long long> v;
	
	uint128_t x = 0;
	
	scanf("%d", &T);

	for(int t = 1; t <= T; ++t)
	{
		scanf("%d %d", &N, &J);
		printf("Case #%d:\n", t);

		string helper(N-2, '0');
		string coin = "1" + helper + "1";
		count = 0;
		first = true;


		while(count < J)
		{
			flag = true;
			v.clear();

			for(int b = 2; flag && b <= 10; ++b)
			{
				val = stoll(coin, 0, b);
				//printf("%lld-", val);
				d = div(val);
				//printf("%lld--", d);
				if(d == 0)
					flag = false;
				else
					v.push_back(d);
			}
			if(flag)
			{
				printf("%s", coin.c_str());
				++count;

				for(int b = 0; b <= 8; ++b)
					printf(" %lld", v[b]);
				printf("\n");
			}
			int k = helper.size()-1;
			while(helper[k] == '1')
				helper[k--] = '0';

			helper[k] = '1';
			coin = "1" + helper + "1";

			//printf("%s\n", coin.c_str());
		}
	}

	return 0;
}