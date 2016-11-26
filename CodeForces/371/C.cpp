#include <set>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	multiset<long long> m;
	int T;
	cin >> T;

	for(int t = 0; t < T; ++t)
	{
		char c;
		cin >> c;
		if(c == '+')
		{
			long long tmp;
			cin >> tmp;
			m.insert(tmp);
		}
		else if(c == '-')
		{
			long long tmp;
			cin >> tmp;
			m.erase(m.find(tmp));
		}
		else
		{
			int cnt = 0;
			string s;
			cin >> s;
			for(const long long& a: m)
			{
				//cout << a << endl;
				long long b = a;
				bool flag = true;
				int i = (int)s.size()-1;
				while(flag && b != 0)
				{
					int tmp = b % 10;
					//cout << tmp << " " << i << " " << s[i] << endl;
					b /= 10;
					if(i >= 0)
					{
						if(s[i] == '0')
						{
							if(tmp % 2 != 0)
								flag = false;
						}
						else
						{
							if(tmp % 2 != 1)
								flag = false;
						}
						--i;
					} 
					else
					{
						if(tmp % 2 != 0)
							flag = false;
					}
				}
				while(flag && i >= 0)
				{
					if(s[i--] != '0')
						flag = false;
				}

				if(flag)
				{
					++cnt;
				}
			}
			cout << cnt << endl;
		}
	}
}