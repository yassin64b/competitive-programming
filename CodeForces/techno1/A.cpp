#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	string s = to_string(b);
	int k = 0;
	while(true)
	{
		++k;
		if(b == a)
		{
			cout << "YES" << endl;
			cout << k << endl;
			cout << s << endl;
			return 0;
		}
		else if(b < a)
		{
			cout << "NO" << endl;
			return 0;
		}
		if(b % 2 == 0)
			s = to_string(b/2) + " " + s, b /= 2;
		else if(b % 10 == 1)
			s = to_string((b-1)/10) + " " + s, b = (b-1)/10;
		else
		{
			cout << "NO" << endl;
			return 0;
		}	
		//cout << b << endl;
	}

	return 0;
}