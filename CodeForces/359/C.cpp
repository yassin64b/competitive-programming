#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

long long convertBase7(long long a)
{
	long long res = 0, mult = 1;
	while(a) 
	{
		res += (a % 7) * mult;
		mult *= 10;
		a /= 7;
	}
	return res;
}

int main()
{
	int n, m;
	cin >> n >> m;

	int nplaces = (n == 0 || n == 1), mplaces = (m == 0 || m == 1);
	long long nt = convertBase7(max(n-1, 0)), mt = convertBase7(max(m-1, 0));

	while(nt)
	{
		++nplaces;
		nt /= 10;
	}
	while(mt)
	{
		++mplaces;
		mt /= 10;
	}

	if(nplaces + mplaces > 7)
	{
		cout << 0 << endl;
		return 0;
	}
	//cout << nplaces << " " << mplaces << endl;
	long long count = 0;
	//(long long)pow(7, nplaces+1)
	for(long long i = 0; i < n; ++i)
	{
		bool flag = true;
		long long itmp = convertBase7(i);
		vector<int> iv(10, 0);
		for(int k = 0; flag && k < nplaces; ++k)
		{
			++iv[itmp%10];
			if(iv[itmp%10] > 1)
				flag = false;
			itmp /= 10;
		}
		for(long long j = 0; flag && j < m; ++j)
		{
			vector<int> jv(iv);
			bool flag2 = true;
			long long jtmp = convertBase7(j);
			for(int k = 0; flag2 && k < mplaces; ++k)
			{
				++jv[jtmp%10];
				if(jv[jtmp%10] > 1)
					flag2 = false;
				jtmp /= 10;
			}
			if(flag2)
			{
				++count;
				//cout << '+' << i << " " << j << endl;
			}
			/*else
			{
				cout << '-' << i << " " << j << endl;
			}*/
		}
	}
	cout << count << endl;
}