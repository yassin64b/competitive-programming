#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MOD ((long long) 1e9 + 7)

using namespace std;

int main()
{
	string s;
	cin >> s;

	int num;
	long long res = 1;
	for(int i = 0; i < (int)s.size(); ++i)
	{
		if(s[i] >= '0' && s[i] <= '9')
			num = s[i] - '0';
		else if(s[i] >= 'A' && s[i] <= 'Z')
			num = s[i] - 'A' + 10;
		else if(s[i] >= 'a' && s[i] <= 'z')
			num = s[i] - 'a' + 36;
		else if(s[i] == '-')
			num = 62;
		else if(s[i] == '_')
			num = 63;

		for(int j = 0; j < 6; ++j)
			if(0 == (num & (1 << j)))
				res = (res * 3) % MOD;

		/*long long tmp = 0;
		for(int j = 0; j < 64; ++j)
			for(int k = 0; k < 64; ++k)
				if(num == (j & k))
					++tmp;
		res = (res * tmp) % MOD);*/
	}
	cout << res << endl;
}